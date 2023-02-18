#include "SLG46826.h"
#include "HAL_SLG46826.h"


bool scanSlg(uint8_t controlCode) {
    if (16 <= controlCode) {
    return false;
    }

    for (uint8_t i = 0; i < 4; i++) {
    uint8_t error SLG_I2Csend(controlCode * 8 + i);
    
    if (error != 0) {
        return false;
    }
    }

    return true;
}

bool readSlg(uint8_t controlCode, uint8_t data[256], uint8_t nvm = 1) {
    if (!scanSlg(controlCode)) {
    return false;
    }

    for (uint8_t i = 0; i < 16; i++) {
    readRegEx(controlCode * 8 + 1 + nvm, i * 16, &data[i * 16], 16);
    }

    return true;
}

bool writeSlg(uint8_t controlCode, const uint8_t data[256], uint8_t mode = 1) {
    log_v("writeSlg(0x%02X, *, %d)", controlCode, mode);

    if (!scanSlg(controlCode)) {
    return false;
    }

    for (uint8_t i = 0; i < 16; i++) {
    writeRegEx(controlCode * 8 + 1 + mode, i * 16, &data[i * 16], 16);
    }

    return true;
}

bool eraseSlg(uint8_t controlCode) {
    log_v("eraseSlg(0x%02X)", controlCode);

    if (!scanSlg(controlCode)) {
    return false;
    }

    for (uint8_t i = 0; i < 16; i++) {
    writeReg(controlCode * 8 + 1, 0xE3, 0x80 + i);
    }

    return true;
}

bool resetSlg(uint8_t controlCode) {
    log_v("resetSlg(0x%02X)", controlCode);

    if (!scanSlg(controlCode)) {
    return false;
    }

    writeReg(controlCode * 8 + 1, 0xC8, 0x02);

    return true;
}

bool digitalRead(uint8_t controlCode, uint8_t pin) {
    if (!scanSlg(controlCode)) {
    return false;
    }

    if (pin <= 8) {
    uint8_t val = readReg(controlCode * 8 + 1, 0x74);
    if (pin == 0) {
        return val & (1 << 1);
    } else if (pin == 1) {
        return val & (1 << 2);
    } else if (pin == 2) {
        return val & (1 << 3);
    } else if (pin == 3) {
        return val & (1 << 4);
    } else if (pin == 4) {
        return val & (1 << 5);
    } else if (pin == 5) {
        return val & (1 << 6);
    } else if (pin == 8) {
        return val & (1 << 7);
    }
    } else {
    uint8_t val = readReg(controlCode * 8 + 1, 0x75);
    if (pin == 9) {
        return val & (1 << 0);
    } else if (pin == 10) {
        return val & (1 << 1);
    } else if (pin == 11) {
        return val & (1 << 2);
    } else if (pin == 12) {
        return val & (1 << 3);
    } else if (pin == 13) {
        return val & (1 << 4);
    } else if (pin == 14) {
        return val & (1 << 5);
    }
    }

    return false;
}

void writeReg(uint8_t reg, uint8_t data) {
    log_v("writeReg(0x%02X, 0x%02X, 0x%02X)", deviceAddress, reg, data);
    //uint32_t clock = _i2cWire->getClock();

    // _i2cWire->setClock(100000);
    // _i2cWire->beginTransmission(deviceAddress);
    // _i2cWire->write(reg);
    SLG_I2Csend(reg);
    // _i2cWire->write(data);
    SLG_I2Csend(data);
    // _i2cWire->endTransmission();
    // _i2cWire->setClock(clock);
    delay(10);
}

void writeRegEx(uint8_t reg, const uint8_t *data, uint8_t size) {
    log_v("writeRegEx(0x%02X, 0x%02X, *, %d)", deviceAddress, reg, size);
    //uint32_t clock = _i2cWire->getClock();
    // _i2cWire->setClock(100000);
    // _i2cWire->beginTransmission(deviceAddress);
    // _i2cWire->write(reg);
    SLG_I2Csend(reg);

    for (int i = 0; i < size; i++) {
    log_v("write(0x%02X)", data[i]);
    // _i2cWire->write(data[i]);
    SLG_I2Csend(data[i]);
    }
    // _i2cWire->endTransmission();
    // _i2cWire->setClock(clock);
    delay(10);
}

uint8_t readReg(uint8_t reg) {
    // _i2cWire->beginTransmission(deviceAddress);
    // _i2cWire->write(reg);
    SLG_I2Csend(reg);
    // _i2cWire->endTransmission();
    // _i2cWire->requestFrom(deviceAddress, (uint8_t)1);
    // return _i2cWire->read();
    return SLG_I2Cread((uint8_t)1);
}

void readRegEx(uint8_t reg, uint8_t *data, uint8_t size) {
    // _i2cWire->beginTransmission(deviceAddress);
    // _i2cWire->write(reg);
    SLG_I2Csend(reg);
    // _i2cWire->endTransmission();
    // _i2cWire->requestFrom(deviceAddress, size);
    //for (uint8_t i = 0; i < size; i++) {
    // data[i] = _i2cWire->read();
    SLG_I2CreadEx(&data[0], (uint8_t)1);
    //}
}

void debug_print_slg46826(const slg_register_t &slgReg) {
  puts();

  puts("%3d(0x%02X) : [60H(0) 768:768(1)] io_fast_pull_up_down_enable\n", slgReg.io_fast_pull_up_down_enable, slgReg.io_fast_pull_up_down_enable);
  puts("%3d(0x%02X) : [60H(1) 769:769(1)] i2c_mode_selection\n", slgReg.i2c_mode_selection, slgReg.i2c_mode_selection);
  puts("%3d(0x%02X) : [61H(0) 777:776(2)] io0_input_mode_configuration\n", slgReg.io0_input_mode_configuration, slgReg.io0_input_mode_configuration);
  puts("%3d(0x%02X) : [61H(2) 779:778(2)] io0_output_mode_configuration\n", slgReg.io0_output_mode_configuration, slgReg.io0_output_mode_configuration);
  puts("%3d(0x%02X) : [61H(4) 781:780(2)] io0_pull_up_down_resistance_selection\n", slgReg.io0_pull_up_down_resistance_selection, slgReg.io0_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [61H(6) 782:782(1)] io0_pull_up_down_selection\n", slgReg.io0_pull_up_down_selection, slgReg.io0_pull_up_down_selection);
  puts("%3d(0x%02X) : [61H(7) 783:783(1)] io0_output_enable\n", slgReg.io0_output_enable, slgReg.io0_output_enable);
  puts("%3d(0x%02X) : [62H(0) 785:784(2)] io1_input_mode_configuration\n", slgReg.io1_input_mode_configuration, slgReg.io1_input_mode_configuration);
  puts("%3d(0x%02X) : [62H(2) 787:786(2)] io1_output_mode_configuration\n", slgReg.io1_output_mode_configuration, slgReg.io1_output_mode_configuration);
  puts("%3d(0x%02X) : [62H(4) 789:788(2)] io1_pull_up_down_resistance_selection\n", slgReg.io1_pull_up_down_resistance_selection, slgReg.io1_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [62H(6) 790:790(1)] io1_pull_up_down_selection\n", slgReg.io1_pull_up_down_selection, slgReg.io1_pull_up_down_selection);
  puts("%3d(0x%02X) : [64H(0) 801:800(2)] io2_input_mode_configuration\n", slgReg.io2_input_mode_configuration, slgReg.io2_input_mode_configuration);
  puts("%3d(0x%02X) : [64H(2) 803:802(2)] io2_output_mode_configuration\n", slgReg.io2_output_mode_configuration, slgReg.io2_output_mode_configuration);
  puts("%3d(0x%02X) : [64H(4) 805:804(2)] io2_pull_up_down_resistance_selection\n", slgReg.io2_pull_up_down_resistance_selection, slgReg.io2_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [64H(6) 806:806(1)] io2_pull_up_down_selection\n", slgReg.io2_pull_up_down_selection, slgReg.io2_pull_up_down_selection);
  puts("%3d(0x%02X) : [64H(7) 807:807(1)] io2_output_enable\n", slgReg.io2_output_enable, slgReg.io2_output_enable);
  puts("%3d(0x%02X) : [65H(0) 809:808(2)] io3_input_mode_configuration\n", slgReg.io3_input_mode_configuration, slgReg.io3_input_mode_configuration);
  puts("%3d(0x%02X) : [65H(2) 811:810(2)] io3_output_mode_configuration\n", slgReg.io3_output_mode_configuration, slgReg.io3_output_mode_configuration);
  puts("%3d(0x%02X) : [65H(4) 813:812(2)] io3_pull_up_down_resistance_selection\n", slgReg.io3_pull_up_down_resistance_selection, slgReg.io3_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [65H(6) 814:814(1)] io3_pull_up_down_selection\n", slgReg.io3_pull_up_down_selection, slgReg.io3_pull_up_down_selection);
  puts("%3d(0x%02X) : [65H(7) 815:815(1)] io3_output_enable\n", slgReg.io3_output_enable, slgReg.io3_output_enable);
  puts("%3d(0x%02X) : [66H(0) 817:816(2)] io4_input_mode_configuration\n", slgReg.io4_input_mode_configuration, slgReg.io4_input_mode_configuration);
  puts("%3d(0x%02X) : [66H(2) 819:818(2)] io4_output_mode_configuration\n", slgReg.io4_output_mode_configuration, slgReg.io4_output_mode_configuration);
  puts("%3d(0x%02X) : [66H(4) 821:820(2)] io4_pull_up_down_resistance_selection\n", slgReg.io4_pull_up_down_resistance_selection, slgReg.io4_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [66H(6) 822:822(1)] io4_pull_up_down_selection\n", slgReg.io4_pull_up_down_selection, slgReg.io4_pull_up_down_selection);
  puts("%3d(0x%02X) : [67H(0) 825:824(2)] io5_input_mode_configuration\n", slgReg.io5_input_mode_configuration, slgReg.io5_input_mode_configuration);
  puts("%3d(0x%02X) : [67H(2) 827:826(2)] io5_output_mode_configuration\n", slgReg.io5_output_mode_configuration, slgReg.io5_output_mode_configuration);
  puts("%3d(0x%02X) : [67H(4) 829:828(2)] io5_pull_up_down_resistance_selection\n", slgReg.io5_pull_up_down_resistance_selection, slgReg.io5_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [67H(6) 830:830(1)] io5_pull_up_down_selection\n", slgReg.io5_pull_up_down_selection, slgReg.io5_pull_up_down_selection);
  puts("%3d(0x%02X) : [68H(1) 834:833(2)] scl_input_mode_configuration\n", slgReg.scl_input_mode_configuration, slgReg.scl_input_mode_configuration);
  puts("%3d(0x%02X) : [68H(3) 836:835(2)] scl_pull_up_down_resistance_selection\n", slgReg.scl_pull_up_down_resistance_selection, slgReg.scl_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [69H(1) 842:841(2)] sda_input_mode_configuration\n", slgReg.sda_input_mode_configuration, slgReg.sda_input_mode_configuration);
  puts("%3d(0x%02X) : [69H(3) 844:843(2)] sda_pull_up_down_resistance_selection\n", slgReg.sda_pull_up_down_resistance_selection, slgReg.sda_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [6AH(2) 851:850(2)] io6_output_mode_configuration\n", slgReg.io6_output_mode_configuration, slgReg.io6_output_mode_configuration);
  puts("%3d(0x%02X) : [6AH(4) 853:852(2)] io6_pull_up_down_resistance_selection\n", slgReg.io6_pull_up_down_resistance_selection, slgReg.io6_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [6AH(6) 854:854(1)] io6_pull_up_down_selection\n", slgReg.io6_pull_up_down_selection, slgReg.io6_pull_up_down_selection);
  puts("%3d(0x%02X) : [6AH(7) 855:855(1)] io6_output_enable\n", slgReg.io6_output_enable, slgReg.io6_output_enable);
  puts("%3d(0x%02X) : [6BH(2) 859:858(2)] io7_output_mode_configuration\n", slgReg.io7_output_mode_configuration, slgReg.io7_output_mode_configuration);
  puts("%3d(0x%02X) : [6BH(4) 861:860(2)] io7_pull_up_down_resistance_selection\n", slgReg.io7_pull_up_down_resistance_selection, slgReg.io7_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [6BH(6) 862:862(1)] io7_pull_up_down_selection\n", slgReg.io7_pull_up_down_selection, slgReg.io7_pull_up_down_selection);
  puts("%3d(0x%02X) : [6BH(7) 863:863(1)] io7_output_enable\n", slgReg.io7_output_enable, slgReg.io7_output_enable);
  puts("%3d(0x%02X) : [6CH(0) 865:864(2)] io8_input_mode_configuration\n", slgReg.io8_input_mode_configuration, slgReg.io8_input_mode_configuration);
  puts("%3d(0x%02X) : [6CH(2) 867:866(2)] io8_output_mode_configuration\n", slgReg.io8_output_mode_configuration, slgReg.io8_output_mode_configuration);
  puts("%3d(0x%02X) : [6CH(4) 869:868(2)] io8_pull_up_down_resistance_selection\n", slgReg.io8_pull_up_down_resistance_selection, slgReg.io8_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [6CH(6) 870:870(1)] io8_pull_up_down_selection\n", slgReg.io8_pull_up_down_selection, slgReg.io8_pull_up_down_selection);
  puts("%3d(0x%02X) : [6EH(0) 881:880(2)] io9_input_mode_configuration\n", slgReg.io9_input_mode_configuration, slgReg.io9_input_mode_configuration);
  puts("%3d(0x%02X) : [6EH(2) 883:882(2)] io9_output_mode_configuration\n", slgReg.io9_output_mode_configuration, slgReg.io9_output_mode_configuration);
  puts("%3d(0x%02X) : [6EH(4) 885:884(2)] io9_pull_up_down_resistance_selection\n", slgReg.io9_pull_up_down_resistance_selection, slgReg.io9_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [6EH(6) 886:886(1)] io9_pull_up_down_selection\n", slgReg.io9_pull_up_down_selection, slgReg.io9_pull_up_down_selection);
  puts("%3d(0x%02X) : [6FH(0) 889:888(2)] io10_input_mode_configuration\n", slgReg.io10_input_mode_configuration, slgReg.io10_input_mode_configuration);
  puts("%3d(0x%02X) : [6FH(2) 891:890(2)] io10_output_mode_configuration\n", slgReg.io10_output_mode_configuration, slgReg.io10_output_mode_configuration);
  puts("%3d(0x%02X) : [6FH(4) 893:892(2)] io10_pull_up_down_resistance_selection\n", slgReg.io10_pull_up_down_resistance_selection, slgReg.io10_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [6FH(6) 894:894(1)] io10_pull_up_down_selection\n", slgReg.io10_pull_up_down_selection, slgReg.io10_pull_up_down_selection);
  puts("%3d(0x%02X) : [70H(0) 897:896(2)] io11_input_mode_configuration\n", slgReg.io11_input_mode_configuration, slgReg.io11_input_mode_configuration);
  puts("%3d(0x%02X) : [70H(2) 899:898(2)] io11_output_mode_configuration\n", slgReg.io11_output_mode_configuration, slgReg.io11_output_mode_configuration);
  puts("%3d(0x%02X) : [70H(4) 901:900(2)] io11_pull_up_down_resistance_selection\n", slgReg.io11_pull_up_down_resistance_selection, slgReg.io11_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [70H(6) 902:902(1)] io11_pull_up_down_selection\n", slgReg.io11_pull_up_down_selection, slgReg.io11_pull_up_down_selection);
  puts("%3d(0x%02X) : [71H(0) 905:904(2)] io12_input_mode_configuration\n", slgReg.io12_input_mode_configuration, slgReg.io12_input_mode_configuration);
  puts("%3d(0x%02X) : [71H(2) 907:906(2)] io12_output_mode_configuration\n", slgReg.io12_output_mode_configuration, slgReg.io12_output_mode_configuration);
  puts("%3d(0x%02X) : [71H(4) 909:908(2)] io12_pull_up_down_resistance_selection\n", slgReg.io12_pull_up_down_resistance_selection, slgReg.io12_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [71H(6) 910:910(1)] io12_pull_up_down_selection\n", slgReg.io12_pull_up_down_selection, slgReg.io12_pull_up_down_selection);
  puts("%3d(0x%02X) : [72H(0) 913:912(2)] io13_input_mode_configuration\n", slgReg.io13_input_mode_configuration, slgReg.io13_input_mode_configuration);
  puts("%3d(0x%02X) : [72H(2) 915:914(2)] io13_output_mode_configuration\n", slgReg.io13_output_mode_configuration, slgReg.io13_output_mode_configuration);
  puts("%3d(0x%02X) : [72H(4) 917:916(2)] io13_pull_up_down_resistance_selection\n", slgReg.io13_pull_up_down_resistance_selection, slgReg.io13_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [72H(6) 918:918(1)] io13_pull_up_down_selection\n", slgReg.io13_pull_up_down_selection, slgReg.io13_pull_up_down_selection);
  puts("%3d(0x%02X) : [73H(0) 921:920(2)] io14_input_mode_configuration\n", slgReg.io14_input_mode_configuration, slgReg.io14_input_mode_configuration);
  puts("%3d(0x%02X) : [73H(2) 923:922(2)] io14_output_mode_configuration\n", slgReg.io14_output_mode_configuration, slgReg.io14_output_mode_configuration);
  puts("%3d(0x%02X) : [73H(4) 925:924(2)] io14_pull_up_down_resistance_selection\n", slgReg.io14_pull_up_down_resistance_selection, slgReg.io14_pull_up_down_resistance_selection);
  puts("%3d(0x%02X) : [73H(6) 926:926(1)] io14_pull_up_down_selection\n", slgReg.io14_pull_up_down_selection, slgReg.io14_pull_up_down_selection);
  puts("%3d(0x%02X) : [74H(1) 929:929(1)] io0_digital_input\n", slgReg.io0_digital_input, slgReg.io0_digital_input);
  puts("%3d(0x%02X) : [74H(2) 930:930(1)] io1_digital_input\n", slgReg.io1_digital_input, slgReg.io1_digital_input);
  puts("%3d(0x%02X) : [74H(3) 931:931(1)] io2_digital_input\n", slgReg.io2_digital_input, slgReg.io2_digital_input);
  puts("%3d(0x%02X) : [74H(4) 932:932(1)] io3_digital_input\n", slgReg.io3_digital_input, slgReg.io3_digital_input);
  puts("%3d(0x%02X) : [74H(5) 933:933(1)] io4_digital_input\n", slgReg.io4_digital_input, slgReg.io4_digital_input);
  puts("%3d(0x%02X) : [74H(6) 934:934(1)] io5_digital_input\n", slgReg.io5_digital_input, slgReg.io5_digital_input);
  puts("%3d(0x%02X) : [74H(7) 935:935(1)] io8_digital_input\n", slgReg.io8_digital_input, slgReg.io8_digital_input);
  puts("%3d(0x%02X) : [75H(0) 936:936(1)] io9_digital_input\n", slgReg.io9_digital_input, slgReg.io9_digital_input);
  puts("%3d(0x%02X) : [75H(1) 937:937(1)] io10_digital_input\n", slgReg.io10_digital_input, slgReg.io10_digital_input);
  puts("%3d(0x%02X) : [75H(2) 938:938(1)] io11_digital_input\n", slgReg.io11_digital_input, slgReg.io11_digital_input);
  puts("%3d(0x%02X) : [75H(3) 939:939(1)] io12_digital_input\n", slgReg.io12_digital_input, slgReg.io12_digital_input);
  puts("%3d(0x%02X) : [75H(4) 940:940(1)] io13_digital_input\n", slgReg.io13_digital_input, slgReg.io13_digital_input);
  puts("%3d(0x%02X) : [75H(5) 941:941(1)] io14_digital_input\n", slgReg.io14_digital_input, slgReg.io14_digital_input);
  puts("%3d(0x%02X) : [75H(6) 942:942(1)] lut2_0_dff0_out\n", slgReg.lut2_0_dff0_out, slgReg.lut2_0_dff0_out);
  puts("%3d(0x%02X) : [75H(7) 943:943(1)] lut2_1_dff1_out\n", slgReg.lut2_1_dff1_out, slgReg.lut2_1_dff1_out);
  puts("%3d(0x%02X) : [76H(0) 944:944(1)] lut2_2_dff2_out\n", slgReg.lut2_2_dff2_out, slgReg.lut2_2_dff2_out);
  puts("%3d(0x%02X) : [76H(1) 945:945(1)] lut2_3_pgen_out\n", slgReg.lut2_3_pgen_out, slgReg.lut2_3_pgen_out);
  puts("%3d(0x%02X) : [76H(2) 946:946(1)] lut3_0_dff3_out\n", slgReg.lut3_0_dff3_out, slgReg.lut3_0_dff3_out);
  puts("%3d(0x%02X) : [76H(3) 947:947(1)] lut3_1_dff4_out\n", slgReg.lut3_1_dff4_out, slgReg.lut3_1_dff4_out);
  puts("%3d(0x%02X) : [76H(4) 948:948(1)] lut3_2_dff5_out\n", slgReg.lut3_2_dff5_out, slgReg.lut3_2_dff5_out);
  puts("%3d(0x%02X) : [76H(5) 949:949(1)] lut3_3_dff6_out\n", slgReg.lut3_3_dff6_out, slgReg.lut3_3_dff6_out);
  puts("%3d(0x%02X) : [76H(6) 950:950(1)] lut3_4_dff7_out\n", slgReg.lut3_4_dff7_out, slgReg.lut3_4_dff7_out);
  puts("%3d(0x%02X) : [76H(7) 951:951(1)] lut3_5_dff8_out\n", slgReg.lut3_5_dff8_out, slgReg.lut3_5_dff8_out);
  puts("%3d(0x%02X) : [77H(0) 952:952(1)] lut3_6_pipedly_ripp_cnt_out0\n", slgReg.lut3_6_pipedly_ripp_cnt_out0, slgReg.lut3_6_pipedly_ripp_cnt_out0);
  puts("%3d(0x%02X) : [77H(1) 953:953(1)] pipedly_ripp_cnt_out1\n", slgReg.pipedly_ripp_cnt_out1, slgReg.pipedly_ripp_cnt_out1);
  puts("%3d(0x%02X) : [77H(2) 954:954(1)] ripp_cnt_out2\n", slgReg.ripp_cnt_out2, slgReg.ripp_cnt_out2);
  puts("%3d(0x%02X) : [77H(3) 955:955(1)] edet_filter_out\n", slgReg.edet_filter_out, slgReg.edet_filter_out);
  puts("%3d(0x%02X) : [77H(4) 956:956(1)] prog_dly_edet_out\n", slgReg.prog_dly_edet_out, slgReg.prog_dly_edet_out);
  puts("%3d(0x%02X) : [77H(5) 957:957(1)] multfunc_8bit_1_dly_cnt_out\n", slgReg.multfunc_8bit_1_dly_cnt_out, slgReg.multfunc_8bit_1_dly_cnt_out);
  puts("%3d(0x%02X) : [77H(6) 958:958(1)] ckosc1_matrix_osc1_matrix_input\n", slgReg.ckosc1_matrix_osc1_matrix_input, slgReg.ckosc1_matrix_osc1_matrix_input);
  puts("%3d(0x%02X) : [77H(7) 959:959(1)] ckosc0_matrix_osc0_matrix_input\n", slgReg.ckosc0_matrix_osc0_matrix_input, slgReg.ckosc0_matrix_osc0_matrix_input);
  puts("%3d(0x%02X) : [78H(0) 960:960(1)] ckosc2_matrix_osc2_matrix_input\n", slgReg.ckosc2_matrix_osc2_matrix_input, slgReg.ckosc2_matrix_osc2_matrix_input);
  puts("%3d(0x%02X) : [78H(1) 961:961(1)] multfunc_8bit_2_dly_cnt_out\n", slgReg.multfunc_8bit_2_dly_cnt_out, slgReg.multfunc_8bit_2_dly_cnt_out);
  puts("%3d(0x%02X) : [78H(2) 962:962(1)] multfunc_8bit_3_dly_cnt_out\n", slgReg.multfunc_8bit_3_dly_cnt_out, slgReg.multfunc_8bit_3_dly_cnt_out);
  puts("%3d(0x%02X) : [78H(3) 963:963(1)] multfunc_8bit_4_dly_cnt_out\n", slgReg.multfunc_8bit_4_dly_cnt_out, slgReg.multfunc_8bit_4_dly_cnt_out);
  puts("%3d(0x%02X) : [78H(4) 964:964(1)] multfunc_8bit_5_dly_cnt_out\n", slgReg.multfunc_8bit_5_dly_cnt_out, slgReg.multfunc_8bit_5_dly_cnt_out);
  puts("%3d(0x%02X) : [78H(5) 965:965(1)] multfunc_8bit_6_dly_cnt_out\n", slgReg.multfunc_8bit_6_dly_cnt_out, slgReg.multfunc_8bit_6_dly_cnt_out);
  puts("%3d(0x%02X) : [78H(6) 966:966(1)] multfunc_8bit_7_dly_cnt_out\n", slgReg.multfunc_8bit_7_dly_cnt_out, slgReg.multfunc_8bit_7_dly_cnt_out);
  puts("%3d(0x%02X) : [78H(7) 967:967(1)] multfunc_16bit_0_lut_dff_out\n", slgReg.multfunc_16bit_0_lut_dff_out, slgReg.multfunc_16bit_0_lut_dff_out);
  puts("%3d(0x%02X) : [79H(0) 968:968(1)] multfunc_8bit_1_lut_dff_out\n", slgReg.multfunc_8bit_1_lut_dff_out, slgReg.multfunc_8bit_1_lut_dff_out);
  puts("%3d(0x%02X) : [79H(1) 969:969(1)] multfunc_8bit_2_lut_dff_out\n", slgReg.multfunc_8bit_2_lut_dff_out, slgReg.multfunc_8bit_2_lut_dff_out);
  puts("%3d(0x%02X) : [79H(2) 970:970(1)] multfunc_8bit_3_lut_dff_out\n", slgReg.multfunc_8bit_3_lut_dff_out, slgReg.multfunc_8bit_3_lut_dff_out);
  puts("%3d(0x%02X) : [79H(3) 971:971(1)] multfunc_8bit_4_lut_dff_out\n", slgReg.multfunc_8bit_4_lut_dff_out, slgReg.multfunc_8bit_4_lut_dff_out);
  puts("%3d(0x%02X) : [79H(4) 972:972(1)] multfunc_8bit_5_lut_dff_out\n", slgReg.multfunc_8bit_5_lut_dff_out, slgReg.multfunc_8bit_5_lut_dff_out);
  puts("%3d(0x%02X) : [79H(5) 973:973(1)] multfunc_8bit_6_lut_dff_out\n", slgReg.multfunc_8bit_6_lut_dff_out, slgReg.multfunc_8bit_6_lut_dff_out);
  puts("%3d(0x%02X) : [79H(6) 974:974(1)] multfunc_8bit_7_lut_dff_out\n", slgReg.multfunc_8bit_7_lut_dff_out, slgReg.multfunc_8bit_7_lut_dff_out);
  puts("%3d(0x%02X) : [79H(7) 975:975(1)] multfunc_16bit_0_dly_cnt_out\n", slgReg.multfunc_16bit_0_dly_cnt_out, slgReg.multfunc_16bit_0_dly_cnt_out);
  puts("%3d(0x%02X) : [7AH(0) 976:976(1)] virtual_input_7\n", slgReg.virtual_input_7, slgReg.virtual_input_7);
  puts("%3d(0x%02X) : [7AH(1) 977:977(1)] virtual_input_6\n", slgReg.virtual_input_6, slgReg.virtual_input_6);
  puts("%3d(0x%02X) : [7AH(2) 978:978(1)] virtual_input_5\n", slgReg.virtual_input_5, slgReg.virtual_input_5);
  puts("%3d(0x%02X) : [7AH(3) 979:979(1)] virtual_input_4\n", slgReg.virtual_input_4, slgReg.virtual_input_4);
  puts("%3d(0x%02X) : [7AH(4) 980:980(1)] virtual_input_3\n", slgReg.virtual_input_3, slgReg.virtual_input_3);
  puts("%3d(0x%02X) : [7AH(5) 981:981(1)] virtual_input_2\n", slgReg.virtual_input_2, slgReg.virtual_input_2);
  puts("%3d(0x%02X) : [7AH(6) 982:982(1)] virtual_input_1\n", slgReg.virtual_input_1, slgReg.virtual_input_1);
  puts("%3d(0x%02X) : [7AH(7) 983:983(1)] virtual_input_0\n", slgReg.virtual_input_0, slgReg.virtual_input_0);
  puts("%3d(0x%02X) : [7BH(2) 986:986(1)] acmp0l_out\n", slgReg.acmp0l_out, slgReg.acmp0l_out);
  puts("%3d(0x%02X) : [7BH(3) 987:987(1)] acmp1l_out\n", slgReg.acmp1l_out, slgReg.acmp1l_out);
  puts("%3d(0x%02X) : [7BH(4) 988:988(1)] second_ckosc1_matrix\n", slgReg.second_ckosc1_matrix, slgReg.second_ckosc1_matrix);
  puts("%3d(0x%02X) : [7BH(5) 989:989(1)] second_ckosc0_matrix\n", slgReg.second_ckosc0_matrix, slgReg.second_ckosc0_matrix);
  puts("%3d(0x%02X) : [7BH(6) 990:990(1)] por_core\n", slgReg.por_core, slgReg.por_core);
  puts("%3d(0x%02X) : [7CH(0) 999:992(8)] cnt0_counted_value_7_0\n", slgReg.cnt0_counted_value_7_0, slgReg.cnt0_counted_value_7_0);
  puts("%3d(0x%02X) : [7DH(0) 1007:1000(8)] cnt0_counted_value_15_8\n", slgReg.cnt0_counted_value_15_8, slgReg.cnt0_counted_value_15_8);
  puts("%3d(0x%02X) : [7EH(0) 1015:1008(8)] cnt2_counted_value\n", slgReg.cnt2_counted_value, slgReg.cnt2_counted_value);
  puts("%3d(0x%02X) : [7FH(0) 1023:1016(8)] cnt4_counted_value\n", slgReg.cnt4_counted_value, slgReg.cnt4_counted_value);
  puts("%3d(0x%02X) : [80H(0) 1024:1024(1)] osc1_turn_on_by_register\n", slgReg.osc1_turn_on_by_register, slgReg.osc1_turn_on_by_register);
  puts("%3d(0x%02X) : [80H(1) 1025:1025(1)] osc1_matrix_power_down_or_on_select\n", slgReg.osc1_matrix_power_down_or_on_select, slgReg.osc1_matrix_power_down_or_on_select);
  puts("%3d(0x%02X) : [80H(2) 1026:1026(1)] osc1_external_clock_source_enable\n", slgReg.osc1_external_clock_source_enable, slgReg.osc1_external_clock_source_enable);
  puts("%3d(0x%02X) : [80H(3) 1028:1027(2)] osc1_post_divider_ration_control\n", slgReg.osc1_post_divider_ration_control, slgReg.osc1_post_divider_ration_control);
  puts("%3d(0x%02X) : [80H(5) 1031:1029(3)] osc1_matrix_divider_ratio_control\n", slgReg.osc1_matrix_divider_ratio_control, slgReg.osc1_matrix_divider_ratio_control);
  puts("%3d(0x%02X) : [81H(0) 1032:1032(1)] osc2_turn_on_by_register\n", slgReg.osc2_turn_on_by_register, slgReg.osc2_turn_on_by_register);
  puts("%3d(0x%02X) : [81H(1) 1033:1033(1)] osc2_matrix_power_down_or_on_select\n", slgReg.osc2_matrix_power_down_or_on_select, slgReg.osc2_matrix_power_down_or_on_select);
  puts("%3d(0x%02X) : [81H(2) 1034:1034(1)] osc2_external_clock_source_enable\n", slgReg.osc2_external_clock_source_enable, slgReg.osc2_external_clock_source_enable);
  puts("%3d(0x%02X) : [81H(3) 1036:1035(2)] osc2_post_divider_ration_control\n", slgReg.osc2_post_divider_ration_control, slgReg.osc2_post_divider_ration_control);
  puts("%3d(0x%02X) : [81H(5) 1039:1037(3)] osc2_matrix_divider_ratio_control\n", slgReg.osc2_matrix_divider_ratio_control, slgReg.osc2_matrix_divider_ratio_control);
  puts("%3d(0x%02X) : [82H(0) 1040:1040(1)] osc0_turn_on_by_register\n", slgReg.osc0_turn_on_by_register, slgReg.osc0_turn_on_by_register);
  puts("%3d(0x%02X) : [82H(1) 1041:1041(1)] osc0_matrix_power_down_or_on_select\n", slgReg.osc0_matrix_power_down_or_on_select, slgReg.osc0_matrix_power_down_or_on_select);
  puts("%3d(0x%02X) : [82H(2) 1042:1042(1)] osc0_external_clock_source_enable\n", slgReg.osc0_external_clock_source_enable, slgReg.osc0_external_clock_source_enable);
  puts("%3d(0x%02X) : [82H(3) 1044:1043(2)] osc0_post_divider_ration_control\n", slgReg.osc0_post_divider_ration_control, slgReg.osc0_post_divider_ration_control);
  puts("%3d(0x%02X) : [82H(5) 1047:1045(3)] osc0_matrix_divider_ratio_control\n", slgReg.osc0_matrix_divider_ratio_control, slgReg.osc0_matrix_divider_ratio_control);
  puts("%3d(0x%02X) : [83H(1) 1049:1049(1)] osc0_matrix_out_enable\n", slgReg.osc0_matrix_out_enable, slgReg.osc0_matrix_out_enable);
  puts("%3d(0x%02X) : [83H(2) 1050:1050(1)] osc1_matrix_out_enable\n", slgReg.osc1_matrix_out_enable, slgReg.osc1_matrix_out_enable);
  puts("%3d(0x%02X) : [83H(3) 1051:1051(1)] osc2_matrix_out_enable\n", slgReg.osc2_matrix_out_enable, slgReg.osc2_matrix_out_enable);
  puts("%3d(0x%02X) : [83H(4) 1052:1052(1)] osc2_100_ns_startup_delay\n", slgReg.osc2_100_ns_startup_delay, slgReg.osc2_100_ns_startup_delay);
  puts("%3d(0x%02X) : [83H(5) 1053:1053(1)] osc0_2nd_matrix_out_enable\n", slgReg.osc0_2nd_matrix_out_enable, slgReg.osc0_2nd_matrix_out_enable);
  puts("%3d(0x%02X) : [83H(6) 1054:1054(1)] osc1_2nd_matrix_out_enable\n", slgReg.osc1_2nd_matrix_out_enable, slgReg.osc1_2nd_matrix_out_enable);
  puts("%3d(0x%02X) : [84H(0) 1058:1056(3)] osc1_2nd_matrix_input_matrix_divider_ratio_control\n", slgReg.osc1_2nd_matrix_input_matrix_divider_ratio_control, slgReg.osc1_2nd_matrix_input_matrix_divider_ratio_control);
  puts("%3d(0x%02X) : [84H(3) 1061:1059(3)] osc0_2nd_matrix_input_matrix_divider_ratio_control\n", slgReg.osc0_2nd_matrix_input_matrix_divider_ratio_control, slgReg.osc0_2nd_matrix_input_matrix_divider_ratio_control);
  puts("%3d(0x%02X) : [87H(2) 1083:1082(2)] acmp0l_hysteresis\n", slgReg.acmp0l_hysteresis, slgReg.acmp0l_hysteresis);
  puts("%3d(0x%02X) : [88H(0) 1089:1088(2)] acmp1l_hysteresis\n", slgReg.acmp1l_hysteresis, slgReg.acmp1l_hysteresis);
  puts("%3d(0x%02X) : [88H(4) 1092:1092(1)] acmp1l_positive_input_come_from_acmp0ls_input_mux_output_enable\n", slgReg.acmp1l_positive_input_come_from_acmp0ls_input_mux_output_enable, slgReg.acmp1l_positive_input_come_from_acmp0ls_input_mux_output_enable);
  puts("%3d(0x%02X) : [8BH(0) 1113:1112(2)] acmp0l_gain_divider\n", slgReg.acmp0l_gain_divider, slgReg.acmp0l_gain_divider);
  puts("%3d(0x%02X) : [8BH(2) 1119:1114(6)] acmp0l_vref\n", slgReg.acmp0l_vref, slgReg.acmp0l_vref);
  puts("%3d(0x%02X) : [8CH(0) 1121:1120(2)] acmp1l_gain_divider\n", slgReg.acmp1l_gain_divider, slgReg.acmp1l_gain_divider);
  puts("%3d(0x%02X) : [8CH(2) 1127:1122(6)] acmp1l_vref\n", slgReg.acmp1l_vref, slgReg.acmp1l_vref);
  puts("%3d(0x%02X) : [8DH(3) 1131:1131(1)] vref_output_op\n", slgReg.vref_output_op, slgReg.vref_output_op);
  puts("%3d(0x%02X) : [8DH(4) 1133:1132(2)] vref0_input_selection\n", slgReg.vref0_input_selection, slgReg.vref0_input_selection);
  puts("%3d(0x%02X) : [8EH(3) 1139:1139(1)] vref_out_pd\n", slgReg.vref_out_pd, slgReg.vref_out_pd);
  puts("%3d(0x%02X) : [90H(0) 1155:1152(4)] lut2_0_dff0_setting\n", slgReg.lut2_0_dff0_setting, slgReg.lut2_0_dff0_setting);
  puts("%3d(0x%02X) : [90H(4) 1159:1156(4)] lut2_1_dff1_setting\n", slgReg.lut2_1_dff1_setting, slgReg.lut2_1_dff1_setting);
  puts("%3d(0x%02X) : [91H(0) 1163:1160(4)] lut2_2_dff2_setting\n", slgReg.lut2_2_dff2_setting, slgReg.lut2_2_dff2_setting);
  puts("%3d(0x%02X) : [91H(4) 1167:1164(4)] lut2_3_val_or_pgen_data\n", slgReg.lut2_3_val_or_pgen_data, slgReg.lut2_3_val_or_pgen_data);
  puts("%3d(0x%02X) : [92H(0) 1175:1168(8)] pgen_data_7_0\n", slgReg.pgen_data_7_0, slgReg.pgen_data_7_0);
  puts("%3d(0x%02X) : [93H(0) 1183:1176(8)] pgen_data_15_8\n", slgReg.pgen_data_15_8, slgReg.pgen_data_15_8);
  puts("%3d(0x%02X) : [94H(0) 1191:1184(8)] lut3_0_dff3_setting\n", slgReg.lut3_0_dff3_setting, slgReg.lut3_0_dff3_setting);
  puts("%3d(0x%02X) : [95H(0) 1199:1192(8)] lut3_1_dff4_setting\n", slgReg.lut3_1_dff4_setting, slgReg.lut3_1_dff4_setting);
  puts("%3d(0x%02X) : [96H(0) 1207:1200(8)] lut3_2_dff5_setting\n", slgReg.lut3_2_dff5_setting, slgReg.lut3_2_dff5_setting);
  puts("%3d(0x%02X) : [97H(0) 1215:1208(8)] lut3_3_dff6_setting\n", slgReg.lut3_3_dff6_setting, slgReg.lut3_3_dff6_setting);
  puts("%3d(0x%02X) : [98H(0) 1223:1216(8)] lut3_4_dff7_setting\n", slgReg.lut3_4_dff7_setting, slgReg.lut3_4_dff7_setting);
  puts("%3d(0x%02X) : [99H(0) 1231:1224(8)] lut3_5_dff8_setting\n", slgReg.lut3_5_dff8_setting, slgReg.lut3_5_dff8_setting);
  puts("%3d(0x%02X) : [9AH(0) 1232:1232(1)] lut2_0_or_dff0_select\n", slgReg.lut2_0_or_dff0_select, slgReg.lut2_0_or_dff0_select);
  puts("%3d(0x%02X) : [9AH(1) 1233:1233(1)] lut2_1_or_dff1_select\n", slgReg.lut2_1_or_dff1_select, slgReg.lut2_1_or_dff1_select);
  puts("%3d(0x%02X) : [9AH(2) 1234:1234(1)] lut2_2_or_dff2_select\n", slgReg.lut2_2_or_dff2_select, slgReg.lut2_2_or_dff2_select);
  puts("%3d(0x%02X) : [9AH(3) 1235:1235(1)] lut2_3_or_pgen_select\n", slgReg.lut2_3_or_pgen_select, slgReg.lut2_3_or_pgen_select);
  puts("%3d(0x%02X) : [9AH(4) 1236:1236(1)] lut3_0_or_dff3_select\n", slgReg.lut3_0_or_dff3_select, slgReg.lut3_0_or_dff3_select);
  puts("%3d(0x%02X) : [9AH(5) 1237:1237(1)] dff3_secondq_sel\n", slgReg.dff3_secondq_sel, slgReg.dff3_secondq_sel);
  puts("%3d(0x%02X) : [9AH(6) 1238:1238(1)] lut3_1_or_dff4_select\n", slgReg.lut3_1_or_dff4_select, slgReg.lut3_1_or_dff4_select);
  puts("%3d(0x%02X) : [9AH(7) 1239:1239(1)] lut3_2_or_dff5_select\n", slgReg.lut3_2_or_dff5_select, slgReg.lut3_2_or_dff5_select);
  puts("%3d(0x%02X) : [9BH(0) 1240:1240(1)] lut3_3_or_dff6_select\n", slgReg.lut3_3_or_dff6_select, slgReg.lut3_3_or_dff6_select);
  puts("%3d(0x%02X) : [9BH(1) 1241:1241(1)] lut3_4_or_dff7_select\n", slgReg.lut3_4_or_dff7_select, slgReg.lut3_4_or_dff7_select);
  puts("%3d(0x%02X) : [9BH(2) 1242:1242(1)] lut3_5_or_dff8_select\n", slgReg.lut3_5_or_dff8_select, slgReg.lut3_5_or_dff8_select);
  puts("%3d(0x%02X) : [9BH(3) 1243:1243(1)] filter_or_edge_detector_selection\n", slgReg.filter_or_edge_detector_selection, slgReg.filter_or_edge_detector_selection);
  puts("%3d(0x%02X) : [9BH(4) 1244:1244(1)] output_polarity_select\n", slgReg.output_polarity_select, slgReg.output_polarity_select);
  puts("%3d(0x%02X) : [9BH(5) 1246:1245(2)] select_the_edge_mode\n", slgReg.select_the_edge_mode, slgReg.select_the_edge_mode);
  puts("%3d(0x%02X) : [9CH(0) 1255:1248(8)] lut_value_or_pipe_delay_out_sel_or_nset_end_value\n", slgReg.lut_value_or_pipe_delay_out_sel_or_nset_end_value, slgReg.lut_value_or_pipe_delay_out_sel_or_nset_end_value);
  puts("%3d(0x%02X) : [9DH(0) 1256:1256(1)] pipe_delay_out1_polarity_select\n", slgReg.pipe_delay_out1_polarity_select, slgReg.pipe_delay_out1_polarity_select);
  puts("%3d(0x%02X) : [9DH(1) 1257:1257(1)] lut3_6_or_pipe_delay_select\n", slgReg.lut3_6_or_pipe_delay_select, slgReg.lut3_6_or_pipe_delay_select);
  puts("%3d(0x%02X) : [9DH(2) 1258:1258(1)] pipe_ripp_cnt_s\n", slgReg.pipe_ripp_cnt_s, slgReg.pipe_ripp_cnt_s);
  puts("%3d(0x%02X) : [9DH(3) 1260:1259(2)] select_the_edge_mode_of_programmable_delay_edge_detector\n", slgReg.select_the_edge_mode_of_programmable_delay_edge_detector, slgReg.select_the_edge_mode_of_programmable_delay_edge_detector);
  puts("%3d(0x%02X) : [9DH(5) 1262:1261(2)] delay_value_select_for_programmable_delay_edge_detector\n", slgReg.delay_value_select_for_programmable_delay_edge_detector, slgReg.delay_value_select_for_programmable_delay_edge_detector);
  puts("%3d(0x%02X) : [A0H(7) 1287:1287(1)] fsm0_set_rst_selection\n", slgReg.fsm0_set_rst_selection, slgReg.fsm0_set_rst_selection);
  puts("%3d(0x%02X) : [A1H(0) 1295:1288(8)] lut4_0_dff9_setting_7_0\n", slgReg.lut4_0_dff9_setting_7_0, slgReg.lut4_0_dff9_setting_7_0);
  puts("%3d(0x%02X) : [A2H(0) 1303:1296(8)] lut4_0_dff9_setting_15_8\n", slgReg.lut4_0_dff9_setting_15_8, slgReg.lut4_0_dff9_setting_15_8);
  puts("%3d(0x%02X) : [A3H(0) 1305:1304(2)] dly_cnt0_mode_selection\n", slgReg.dly_cnt0_mode_selection, slgReg.dly_cnt0_mode_selection);
  puts("%3d(0x%02X) : [A3H(2) 1307:1306(2)] dly_cnt0_edge_mode_selection\n", slgReg.dly_cnt0_edge_mode_selection, slgReg.dly_cnt0_edge_mode_selection);
  puts("%3d(0x%02X) : [A3H(4) 1311:1308(4)] dly_cnt0_clock_source_select\n", slgReg.dly_cnt0_clock_source_select, slgReg.dly_cnt0_clock_source_select);
  puts("%3d(0x%02X) : [A4H(0) 1312:1312(1)] cnt0_output_pol_selection\n", slgReg.cnt0_output_pol_selection, slgReg.cnt0_output_pol_selection);
  puts("%3d(0x%02X) : [A4H(1) 1314:1313(2)] cnt0_initial_value_selection\n", slgReg.cnt0_initial_value_selection, slgReg.cnt0_initial_value_selection);
  puts("%3d(0x%02X) : [A4H(5) 1317:1317(1)] keep_signal_sync_selection\n", slgReg.keep_signal_sync_selection, slgReg.keep_signal_sync_selection);
  puts("%3d(0x%02X) : [A4H(6) 1318:1318(1)] up_signal_sync_selection\n", slgReg.up_signal_sync_selection, slgReg.up_signal_sync_selection);
  puts("%3d(0x%02X) : [A4H(7) 1319:1319(1)] cnt0_dly_edet_function_selection\n", slgReg.cnt0_dly_edet_function_selection, slgReg.cnt0_dly_edet_function_selection);
  puts("%3d(0x%02X) : [A5H(0) 1327:1320(8)] reg_cnt0_data_7_0\n", slgReg.reg_cnt0_data_7_0, slgReg.reg_cnt0_data_7_0);
  puts("%3d(0x%02X) : [A6H(0) 1335:1328(8)] reg_cnt0_data_15_8\n", slgReg.reg_cnt0_data_15_8, slgReg.reg_cnt0_data_15_8);
  puts("%3d(0x%02X) : [A7H(0) 1336:1336(1)] cnt0_cnt_mode_sync_selection\n", slgReg.cnt0_cnt_mode_sync_selection, slgReg.cnt0_cnt_mode_sync_selection);
  puts("%3d(0x%02X) : [A7H(6) 1343:1342(2)] cnt1_initial_value_selection\n", slgReg.cnt1_initial_value_selection, slgReg.cnt1_initial_value_selection);
  puts("%3d(0x%02X) : [A8H(0) 1351:1344(8)] lut3_7_dff10_setting\n", slgReg.lut3_7_dff10_setting, slgReg.lut3_7_dff10_setting);
  puts("%3d(0x%02X) : [A9H(0) 1355:1352(4)] dly_cnt1_clock_source_select\n", slgReg.dly_cnt1_clock_source_select, slgReg.dly_cnt1_clock_source_select);
  puts("%3d(0x%02X) : [A9H(4) 1359:1356(4)] cnt1_function_and_edge_mode_selection\n", slgReg.cnt1_function_and_edge_mode_selection, slgReg.cnt1_function_and_edge_mode_selection);
  puts("%3d(0x%02X) : [AAH(0) 1367:1360(8)] reg_cnt1_data\n", slgReg.reg_cnt1_data, slgReg.reg_cnt1_data);
  puts("%3d(0x%02X) : [ABH(0) 1368:1368(1)] cnt1_output_pol_selection\n", slgReg.cnt1_output_pol_selection, slgReg.cnt1_output_pol_selection);
  puts("%3d(0x%02X) : [ABH(2) 1370:1370(1)] cnt1_cnt_mode_sync_selection\n", slgReg.cnt1_cnt_mode_sync_selection, slgReg.cnt1_cnt_mode_sync_selection);
  puts("%3d(0x%02X) : [ABH(3) 1371:1371(1)] cnt1_dly_edet_function_selection\n", slgReg.cnt1_dly_edet_function_selection, slgReg.cnt1_dly_edet_function_selection);
  puts("%3d(0x%02X) : [ACH(0) 1383:1376(8)] lut3_8_dff_11_setting\n", slgReg.lut3_8_dff_11_setting, slgReg.lut3_8_dff_11_setting);
  puts("%3d(0x%02X) : [ADH(0) 1387:1384(4)] dly_cnt2_clock_source_select\n", slgReg.dly_cnt2_clock_source_select, slgReg.dly_cnt2_clock_source_select);
  puts("%3d(0x%02X) : [ADH(4) 1391:1388(4)] cnt2_function_and_edge_mode_selection\n", slgReg.cnt2_function_and_edge_mode_selection, slgReg.cnt2_function_and_edge_mode_selection);
  puts("%3d(0x%02X) : [AEH(0) 1393:1392(2)] cnt2_initial_value_selection\n", slgReg.cnt2_initial_value_selection, slgReg.cnt2_initial_value_selection);
  puts("%3d(0x%02X) : [AEH(3) 1395:1395(1)] cnt2_output_pol_selection\n", slgReg.cnt2_output_pol_selection, slgReg.cnt2_output_pol_selection);
  puts("%3d(0x%02X) : [AEH(5) 1397:1397(1)] cnt2_cnt_mode_sync_selection\n", slgReg.cnt2_cnt_mode_sync_selection, slgReg.cnt2_cnt_mode_sync_selection);
  puts("%3d(0x%02X) : [AEH(6) 1398:1398(1)] cnt2_dly_edet_function_selection\n", slgReg.cnt2_dly_edet_function_selection, slgReg.cnt2_dly_edet_function_selection);
  puts("%3d(0x%02X) : [AFH(0) 1407:1400(8)] reg_cnt2_data\n", slgReg.reg_cnt2_data, slgReg.reg_cnt2_data);
  puts("%3d(0x%02X) : [B0H(6) 1415:1414(2)] cnt3_initial_value_selection\n", slgReg.cnt3_initial_value_selection, slgReg.cnt3_initial_value_selection);
  puts("%3d(0x%02X) : [B1H(0) 1423:1416(8)] lut3_9_dff12_setting\n", slgReg.lut3_9_dff12_setting, slgReg.lut3_9_dff12_setting);
  puts("%3d(0x%02X) : [B2H(0) 1427:1424(4)] dly_cnt3_clock_source_select\n", slgReg.dly_cnt3_clock_source_select, slgReg.dly_cnt3_clock_source_select);
  puts("%3d(0x%02X) : [B2H(4) 1431:1428(4)] cnt3_function_and_edge_mode_selection\n", slgReg.cnt3_function_and_edge_mode_selection, slgReg.cnt3_function_and_edge_mode_selection);
  puts("%3d(0x%02X) : [B3H(0) 1439:1432(8)] reg_cnt3_data\n", slgReg.reg_cnt3_data, slgReg.reg_cnt3_data);
  puts("%3d(0x%02X) : [B4H(0) 1440:1440(1)] cnt3_output_pol_selection\n", slgReg.cnt3_output_pol_selection, slgReg.cnt3_output_pol_selection);
  puts("%3d(0x%02X) : [B4H(2) 1442:1442(1)] cnt3_cnt_mode_sync_selection\n", slgReg.cnt3_cnt_mode_sync_selection, slgReg.cnt3_cnt_mode_sync_selection);
  puts("%3d(0x%02X) : [B4H(3) 1443:1443(1)] cnt3_dly_edet_function_selection\n", slgReg.cnt3_dly_edet_function_selection, slgReg.cnt3_dly_edet_function_selection);
  puts("%3d(0x%02X) : [B5H(0) 1455:1448(8)] lut3_dff_setting\n", slgReg.lut3_dff_setting, slgReg.lut3_dff_setting);
  puts("%3d(0x%02X) : [B6H(0) 1459:1456(4)] dly_cnt4_clock_source_select\n", slgReg.dly_cnt4_clock_source_select, slgReg.dly_cnt4_clock_source_select);
  puts("%3d(0x%02X) : [B6H(4) 1463:1460(4)] cnt4_function_and_edge_mode_selection\n", slgReg.cnt4_function_and_edge_mode_selection, slgReg.cnt4_function_and_edge_mode_selection);
  puts("%3d(0x%02X) : [B7H(0) 1465:1464(2)] cnt4_initial_value_selection\n", slgReg.cnt4_initial_value_selection, slgReg.cnt4_initial_value_selection);
  puts("%3d(0x%02X) : [B7H(3) 1467:1467(1)] cnt4_output_pol_selection\n", slgReg.cnt4_output_pol_selection, slgReg.cnt4_output_pol_selection);
  puts("%3d(0x%02X) : [B7H(5) 1469:1469(1)] cnt4_cnt_mode_sync_selection\n", slgReg.cnt4_cnt_mode_sync_selection, slgReg.cnt4_cnt_mode_sync_selection);
  puts("%3d(0x%02X) : [B7H(6) 1470:1470(1)] cnt4_dly_edet_function_selection\n", slgReg.cnt4_dly_edet_function_selection, slgReg.cnt4_dly_edet_function_selection);
  puts("%3d(0x%02X) : [B8H(0) 1479:1472(8)] reg_cnt4_data\n", slgReg.reg_cnt4_data, slgReg.reg_cnt4_data);
  puts("%3d(0x%02X) : [B9H(6) 1487:1486(2)] cnt5_initial_value_selection\n", slgReg.cnt5_initial_value_selection, slgReg.cnt5_initial_value_selection);
  puts("%3d(0x%02X) : [BAH(0) 1495:1488(8)] lut3_11_dff14_setting\n", slgReg.lut3_11_dff14_setting, slgReg.lut3_11_dff14_setting);
  puts("%3d(0x%02X) : [BBH(0) 1499:1496(4)] dly_cnt5_clock_source_select\n", slgReg.dly_cnt5_clock_source_select, slgReg.dly_cnt5_clock_source_select);
  puts("%3d(0x%02X) : [BBH(4) 1503:1500(4)] cnt5_function_and_edge_mode_selection\n", slgReg.cnt5_function_and_edge_mode_selection, slgReg.cnt5_function_and_edge_mode_selection);
  puts("%3d(0x%02X) : [BCH(0) 1511:1504(8)] reg_cnt5_data\n", slgReg.reg_cnt5_data, slgReg.reg_cnt5_data);
  puts("%3d(0x%02X) : [BDH(0) 1512:1512(1)] cnt5_output_pol_selection\n", slgReg.cnt5_output_pol_selection, slgReg.cnt5_output_pol_selection);
  puts("%3d(0x%02X) : [BDH(2) 1514:1514(1)] cnt5_cnt_mode_sync_selection\n", slgReg.cnt5_cnt_mode_sync_selection, slgReg.cnt5_cnt_mode_sync_selection);
  puts("%3d(0x%02X) : [BDH(3) 1515:1515(1)] cnt5_dly_edet_function_selection\n", slgReg.cnt5_dly_edet_function_selection, slgReg.cnt5_dly_edet_function_selection);
  puts("%3d(0x%02X) : [BEH(0) 1527:1520(8)] lut3_12_dff15_setting\n", slgReg.lut3_12_dff15_setting, slgReg.lut3_12_dff15_setting);
  puts("%3d(0x%02X) : [BFH(0) 1531:1528(4)] dly_cnt6_clock_source_select\n", slgReg.dly_cnt6_clock_source_select, slgReg.dly_cnt6_clock_source_select);
  puts("%3d(0x%02X) : [BFH(4) 1535:1532(4)] cnt6_function_and_edge_mode_selection\n", slgReg.cnt6_function_and_edge_mode_selection, slgReg.cnt6_function_and_edge_mode_selection);
  puts("%3d(0x%02X) : [C0H(0) 1537:1536(2)] cnt6_initial_value_selection\n", slgReg.cnt6_initial_value_selection, slgReg.cnt6_initial_value_selection);
  puts("%3d(0x%02X) : [C0H(3) 1539:1539(1)] cnt6_output_pol_selection\n", slgReg.cnt6_output_pol_selection, slgReg.cnt6_output_pol_selection);
  puts("%3d(0x%02X) : [C0H(5) 1541:1541(1)] cnt6_cnt_mode_sync_selection\n", slgReg.cnt6_cnt_mode_sync_selection, slgReg.cnt6_cnt_mode_sync_selection);
  puts("%3d(0x%02X) : [C0H(6) 1542:1542(1)] cnt6_dly_edet_function_selection\n", slgReg.cnt6_dly_edet_function_selection, slgReg.cnt6_dly_edet_function_selection);
  puts("%3d(0x%02X) : [C1H(0) 1551:1544(8)] reg_cnt6_data\n", slgReg.reg_cnt6_data, slgReg.reg_cnt6_data);
  puts("%3d(0x%02X) : [C2H(5) 1557:1557(1)] cnt7_output_pol_selection\n", slgReg.cnt7_output_pol_selection, slgReg.cnt7_output_pol_selection);
  puts("%3d(0x%02X) : [C2H(7) 1559:1559(1)] cnt7_cnt_mode_sync_selection\n", slgReg.cnt7_cnt_mode_sync_selection, slgReg.cnt7_cnt_mode_sync_selection);
  puts("%3d(0x%02X) : [C3H(0) 1567:1560(8)] lut3_13_dff16_setting\n", slgReg.lut3_13_dff16_setting, slgReg.lut3_13_dff16_setting);
  puts("%3d(0x%02X) : [C4H(0) 1571:1568(4)] dly_cnt7_clock_source_select\n", slgReg.dly_cnt7_clock_source_select, slgReg.dly_cnt7_clock_source_select);
  puts("%3d(0x%02X) : [C4H(4) 1575:1572(4)] cnt7_function_and_edge_mode_selection\n", slgReg.cnt7_function_and_edge_mode_selection, slgReg.cnt7_function_and_edge_mode_selection);
  puts("%3d(0x%02X) : [C5H(0) 1577:1576(2)] cnt7_initial_value_selection\n", slgReg.cnt7_initial_value_selection, slgReg.cnt7_initial_value_selection);
  puts("%3d(0x%02X) : [C5H(2) 1578:1578(1)] cnt7_dly_edet_function_selection\n", slgReg.cnt7_dly_edet_function_selection, slgReg.cnt7_dly_edet_function_selection);
  puts("%3d(0x%02X) : [C6H(0) 1591:1584(8)] reg_cnt7_data\n", slgReg.reg_cnt7_data, slgReg.reg_cnt7_data);
  puts("%3d(0x%02X) : [C7H(0) 1592:1592(1)] io0_i2c_output_expander_data\n", slgReg.io0_i2c_output_expander_data, slgReg.io0_i2c_output_expander_data);
  puts("%3d(0x%02X) : [C7H(1) 1593:1593(1)] io0_i2c_output_expander_select\n", slgReg.io0_i2c_output_expander_select, slgReg.io0_i2c_output_expander_select);
  puts("%3d(0x%02X) : [C7H(2) 1594:1594(1)] io5_i2c_output_expander_data\n", slgReg.io5_i2c_output_expander_data, slgReg.io5_i2c_output_expander_data);
  puts("%3d(0x%02X) : [C7H(3) 1595:1595(1)] io5_i2c_output_expander_select\n", slgReg.io5_i2c_output_expander_select, slgReg.io5_i2c_output_expander_select);
  puts("%3d(0x%02X) : [C7H(4) 1596:1596(1)] io6_i2c_output_expander_data\n", slgReg.io6_i2c_output_expander_data, slgReg.io6_i2c_output_expander_data);
  puts("%3d(0x%02X) : [C7H(5) 1597:1597(1)] io6_i2c_output_expander_select\n", slgReg.io6_i2c_output_expander_select, slgReg.io6_i2c_output_expander_select);
  puts("%3d(0x%02X) : [C7H(6) 1598:1598(1)] io9_i2c_output_expander_data\n", slgReg.io9_i2c_output_expander_data, slgReg.io9_i2c_output_expander_data);
  puts("%3d(0x%02X) : [C7H(7) 1599:1599(1)] io9_i2c_output_expander_select\n", slgReg.io9_i2c_output_expander_select, slgReg.io9_i2c_output_expander_select);
  puts("%3d(0x%02X) : [C8H(1) 1601:1601(1)] i2c_reset_bit_with_reloading_nvm_into_data_register_soft_reset\n", slgReg.i2c_reset_bit_with_reloading_nvm_into_data_register_soft_reset, slgReg.i2c_reset_bit_with_reloading_nvm_into_data_register_soft_reset);
  puts("%3d(0x%02X) : [C8H(2) 1602:1602(1)] io_latching_enable_during_i2c_write_interface\n", slgReg.io_latching_enable_during_i2c_write_interface, slgReg.io_latching_enable_during_i2c_write_interface);
  puts("%3d(0x%02X) : [C9H(0) 1615:1608(8)] i2c_write_mask_bits\n", slgReg.i2c_write_mask_bits, slgReg.i2c_write_mask_bits);
  puts("%3d(0x%02X) : [CAH(0) 1619:1616(4)] i2c_slave_address\n", slgReg.i2c_slave_address, slgReg.i2c_slave_address);
  puts("%3d(0x%02X) : [CAH(4) 1620:1620(1)] slave_address_selection_a4\n", slgReg.slave_address_selection_a4, slgReg.slave_address_selection_a4);
  puts("%3d(0x%02X) : [CAH(5) 1621:1621(1)] slave_address_selection_a5\n", slgReg.slave_address_selection_a5, slgReg.slave_address_selection_a5);
  puts("%3d(0x%02X) : [CAH(6) 1622:1622(1)] slave_address_selection_a6\n", slgReg.slave_address_selection_a6, slgReg.slave_address_selection_a6);
  puts("%3d(0x%02X) : [CAH(7) 1623:1623(1)] slave_address_selection_a7\n", slgReg.slave_address_selection_a7, slgReg.slave_address_selection_a7);
  puts("%3d(0x%02X) : [CBH(0) 1631:1624(8)] pattern_id_byte_0\n", slgReg.pattern_id_byte_0, slgReg.pattern_id_byte_0);
  puts("%3d(0x%02X) : [E0H(0) 1793:1792(2)] register_read_selection_bits\n", slgReg.register_read_selection_bits, slgReg.register_read_selection_bits);
  puts("%3d(0x%02X) : [E0H(2) 1795:1794(2)] register_write_selection_bits\n", slgReg.register_write_selection_bits, slgReg.register_write_selection_bits);
  puts("%3d(0x%02X) : [E1H(0) 1801:1800(2)] nvm_configuration_selection_bits\n", slgReg.nvm_configuration_selection_bits, slgReg.nvm_configuration_selection_bits);
  puts("%3d(0x%02X) : [E2H(2) 1810:1810(1)] write_protect_register_enable\n", slgReg.write_protect_register_enable, slgReg.write_protect_register_enable);
  puts("%3d(0x%02X) : [E3H(0) 1820:1816(5)] page_selection_for_erase_erseb\n", slgReg.page_selection_for_erase_erseb, slgReg.page_selection_for_erase_erseb);
  puts("%3d(0x%02X) : [E3H(7) 1823:1823(1)] erase_enable\n", slgReg.erase_enable, slgReg.erase_enable);
  puts("%3d(0x%02X) : [E4H(0) 1824:1824(1)] protection_lock_bit_prl\n", slgReg.protection_lock_bit_prl, slgReg.protection_lock_bit_prl);

  puts();
}


