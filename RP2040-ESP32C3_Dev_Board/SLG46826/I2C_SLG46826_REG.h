#ifndef __I2C_SLG46826_REG_H__
#define __I2C_SLG46826_REG_H__

typedef struct {
  union {
    struct {
      union {
        uint8_t reg_00;
      };
      union {
        uint8_t reg_01;
      };
      union {
        uint8_t reg_02;
      };
      union {
        uint8_t reg_03;
      };
      union {
        uint8_t reg_04;
      };
      union {
        uint8_t reg_05;
      };
      union {
        uint8_t reg_06;
      };
      union {
        uint8_t reg_07;
      };
      union {
        uint8_t reg_08;
      };
      union {
        uint8_t reg_09;
      };
      union {
        uint8_t reg_0a;
      };
      union {
        uint8_t reg_0b;
      };
      union {
        uint8_t reg_0c;
      };
      union {
        uint8_t reg_0d;
      };
      union {
        uint8_t reg_0e;
      };
      union {
        uint8_t reg_0f;
      };
      union {
        uint8_t reg_10;
      };
      union {
        uint8_t reg_11;
      };
      union {
        uint8_t reg_12;
      };
      union {
        uint8_t reg_13;
      };
      union {
        uint8_t reg_14;
      };
      union {
        uint8_t reg_15;
      };
      union {
        uint8_t reg_16;
      };
      union {
        uint8_t reg_17;
      };
      union {
        uint8_t reg_18;
      };
      union {
        uint8_t reg_19;
      };
      union {
        uint8_t reg_1a;
      };
      union {
        uint8_t reg_1b;
      };
      union {
        uint8_t reg_1c;
      };
      union {
        uint8_t reg_1d;
      };
      union {
        uint8_t reg_1e;
      };
      union {
        uint8_t reg_1f;
      };
      union {
        uint8_t reg_20;
      };
      union {
        uint8_t reg_21;
      };
      union {
        uint8_t reg_22;
      };
      union {
        uint8_t reg_23;
      };
      union {
        uint8_t reg_24;
      };
      union {
        uint8_t reg_25;
      };
      union {
        uint8_t reg_26;
      };
      union {
        uint8_t reg_27;
      };
      union {
        uint8_t reg_28;
      };
      union {
        uint8_t reg_29;
      };
      union {
        uint8_t reg_2a;
      };
      union {
        uint8_t reg_2b;
      };
      union {
        uint8_t reg_2c;
      };
      union {
        uint8_t reg_2d;
      };
      union {
        uint8_t reg_2e;
      };
      union {
        uint8_t reg_2f;
      };
      union {
        uint8_t reg_30;
      };
      union {
        uint8_t reg_31;
      };
      union {
        uint8_t reg_32;
      };
      union {
        uint8_t reg_33;
      };
      union {
        uint8_t reg_34;
      };
      union {
        uint8_t reg_35;
      };
      union {
        uint8_t reg_36;
      };
      union {
        uint8_t reg_37;
      };
      union {
        uint8_t reg_38;
      };
      union {
        uint8_t reg_39;
      };
      union {
        uint8_t reg_3a;
      };
      union {
        uint8_t reg_3b;
      };
      union {
        uint8_t reg_3c;
      };
      union {
        uint8_t reg_3d;
      };
      union {
        uint8_t reg_3e;
      };
      union {
        uint8_t reg_3f;
      };
      union {
        uint8_t reg_40;
      };
      union {
        uint8_t reg_41;
      };
      union {
        uint8_t reg_42;
      };
      union {
        uint8_t reg_43;
      };
      union {
        uint8_t reg_44;
      };
      union {
        uint8_t reg_45;
      };
      union {
        uint8_t reg_46;
      };
      union {
        uint8_t reg_47;
      };
      union {
        uint8_t reg_48;
      };
      union {
        uint8_t reg_49;
      };
      union {
        uint8_t reg_4a;
      };
      union {
        uint8_t reg_4b;
      };
      union {
        uint8_t reg_4c;
      };
      union {
        uint8_t reg_4d;
      };
      union {
        uint8_t reg_4e;
      };
      union {
        uint8_t reg_4f;
      };
      union {
        uint8_t reg_50;
      };
      union {
        uint8_t reg_51;
      };
      union {
        uint8_t reg_52;
      };
      union {
        uint8_t reg_53;
      };
      union {
        uint8_t reg_54;
      };
      union {
        uint8_t reg_55;
      };
      union {
        uint8_t reg_56;
      };
      union {
        uint8_t reg_57;
      };
      union {
        uint8_t reg_58;
      };
      union {
        uint8_t reg_59;
      };
      union {
        uint8_t reg_5a;
      };
      union {
        uint8_t reg_5b;
      };
      union {
        uint8_t reg_5c;
      };
      union {
        uint8_t reg_5d;
      };
      union {
        uint8_t reg_5e;
      };
      union {
        uint8_t reg_5f;
      };
      union {
        struct {
          uint8_t io_fast_pull_up_down_enable: 1; // [60H(0), 768:768]
          uint8_t i2c_mode_selection: 1;          // [60H(1), 769:769]
        };
        uint8_t reg_60;
      };
      union {
        struct {
          uint8_t io0_input_mode_configuration: 2;          // [61H(0), 777:776]
          uint8_t io0_output_mode_configuration: 2;         // [61H(2), 779:778]
          uint8_t io0_pull_up_down_resistance_selection: 2; // [61H(4), 781:780]
          uint8_t io0_pull_up_down_selection: 1;            // [61H(6), 782:782]
          uint8_t io0_output_enable: 1;                     // [61H(7), 783:783]
        };
        uint8_t reg_61;
      };
      union {
        struct {
          uint8_t io1_input_mode_configuration: 2;          // [62H(0), 785:784]
          uint8_t io1_output_mode_configuration: 2;         // [62H(2), 787:786]
          uint8_t io1_pull_up_down_resistance_selection: 2; // [62H(4), 789:788]
          uint8_t io1_pull_up_down_selection: 1;            // [62H(6), 790:790]
        };
        uint8_t reg_62;
      };
      union {
        uint8_t reg_63;
      };
      union {
        struct {
          uint8_t io2_input_mode_configuration: 2;          // [64H(0), 801:800]
          uint8_t io2_output_mode_configuration: 2;         // [64H(2), 803:802]
          uint8_t io2_pull_up_down_resistance_selection: 2; // [64H(4), 805:804]
          uint8_t io2_pull_up_down_selection: 1;            // [64H(6), 806:806]
          uint8_t io2_output_enable: 1;                     // [64H(7), 807:807]
        };
        uint8_t reg_64;
      };
      union {
        struct {
          uint8_t io3_input_mode_configuration: 2;          // [65H(0), 809:808]
          uint8_t io3_output_mode_configuration: 2;         // [65H(2), 811:810]
          uint8_t io3_pull_up_down_resistance_selection: 2; // [65H(4), 813:812]
          uint8_t io3_pull_up_down_selection: 1;            // [65H(6), 814:814]
          uint8_t io3_output_enable: 1;                     // [65H(7), 815:815]
        };
        uint8_t reg_65;
      };
      union {
        struct {
          uint8_t io4_input_mode_configuration: 2;          // [66H(0), 817:816]
          uint8_t io4_output_mode_configuration: 2;         // [66H(2), 819:818]
          uint8_t io4_pull_up_down_resistance_selection: 2; // [66H(4), 821:820]
          uint8_t io4_pull_up_down_selection: 1;            // [66H(6), 822:822]
        };
        uint8_t reg_66;
      };
      union {
        struct {
          uint8_t io5_input_mode_configuration: 2;          // [67H(0), 825:824]
          uint8_t io5_output_mode_configuration: 2;         // [67H(2), 827:826]
          uint8_t io5_pull_up_down_resistance_selection: 2; // [67H(4), 829:828]
          uint8_t io5_pull_up_down_selection: 1;            // [67H(6), 830:830]
        };
        uint8_t reg_67;
      };
      union {
        struct {
          uint8_t : 1;                                      // [68H(0), 832:832]
          uint8_t scl_input_mode_configuration: 2;          // [68H(1), 834:833]
          uint8_t scl_pull_up_down_resistance_selection: 2; // [68H(3), 836:835]
        };
        uint8_t reg_68;
      };
      union {
        struct {
          uint8_t : 1;                                      // [69H(0), 840:840]
          uint8_t sda_input_mode_configuration: 2;          // [69H(1), 842:841]
          uint8_t sda_pull_up_down_resistance_selection: 2; // [69H(3), 844:843]
        };
        uint8_t reg_69;
      };
      union {
        struct {
          uint8_t : 2;                                      // [6AH(0), 849:848]
          uint8_t io6_output_mode_configuration: 2;         // [6AH(2), 851:850]
          uint8_t io6_pull_up_down_resistance_selection: 2; // [6AH(4), 853:852]
          uint8_t io6_pull_up_down_selection: 1;            // [6AH(6), 854:854]
          uint8_t io6_output_enable: 1;                     // [6AH(7), 855:855]
        };
        uint8_t reg_6a;
      };
      union {
        struct {
          uint8_t : 2;                                      // [6BH(0), 857:856]
          uint8_t io7_output_mode_configuration: 2;         // [6BH(2), 859:858]
          uint8_t io7_pull_up_down_resistance_selection: 2; // [6BH(4), 861:860]
          uint8_t io7_pull_up_down_selection: 1;            // [6BH(6), 862:862]
          uint8_t io7_output_enable: 1;                     // [6BH(7), 863:863]
        };
        uint8_t reg_6b;
      };
      union {
        struct {
          uint8_t io8_input_mode_configuration: 2;          // [6CH(0), 865:864]
          uint8_t io8_output_mode_configuration: 2;         // [6CH(2), 867:866]
          uint8_t io8_pull_up_down_resistance_selection: 2; // [6CH(4), 869:868]
          uint8_t io8_pull_up_down_selection: 1;            // [6CH(6), 870:870]
        };
        uint8_t reg_6c;
      };
      union {
        uint8_t reg_6d;
      };
      union {
        struct {
          uint8_t io9_input_mode_configuration: 2;          // [6EH(0), 881:880]
          uint8_t io9_output_mode_configuration: 2;         // [6EH(2), 883:882]
          uint8_t io9_pull_up_down_resistance_selection: 2; // [6EH(4), 885:884]
          uint8_t io9_pull_up_down_selection: 1;            // [6EH(6), 886:886]
        };
        uint8_t reg_6e;
      };
      union {
        struct {
          uint8_t io10_input_mode_configuration: 2;           // [6FH(0), 889:888]
          uint8_t io10_output_mode_configuration: 2;          // [6FH(2), 891:890]
          uint8_t io10_pull_up_down_resistance_selection: 2;  // [6FH(4), 893:892]
          uint8_t io10_pull_up_down_selection: 1;             // [6FH(6), 894:894]
        };
        uint8_t reg_6f;
      };
      union {
        struct {
          uint8_t io11_input_mode_configuration: 2;           // [70H(0), 897:896]
          uint8_t io11_output_mode_configuration: 2;          // [70H(2), 899:898]
          uint8_t io11_pull_up_down_resistance_selection: 2;  // [70H(4), 901:900]
          uint8_t io11_pull_up_down_selection: 1;             // [70H(6), 902:902]
        };
        uint8_t reg_70;
      };
      union {
        struct {
          uint8_t io12_input_mode_configuration: 2;           // [71H(0), 905:904]
          uint8_t io12_output_mode_configuration: 2;          // [71H(2), 907:906]
          uint8_t io12_pull_up_down_resistance_selection: 2;  // [71H(4), 909:908]
          uint8_t io12_pull_up_down_selection: 1;             // [71H(6), 910:910]
        };
        uint8_t reg_71;
      };
      union {
        struct {
          uint8_t io13_input_mode_configuration: 2;           // [72H(0), 913:912]
          uint8_t io13_output_mode_configuration: 2;          // [72H(2), 915:914]
          uint8_t io13_pull_up_down_resistance_selection: 2;  // [72H(4), 917:916]
          uint8_t io13_pull_up_down_selection: 1;             // [72H(6), 918:918]
        };
        uint8_t reg_72;
      };
      union {
        struct {
          uint8_t io14_input_mode_configuration: 2;           // [73H(0), 921:920]
          uint8_t io14_output_mode_configuration: 2;          // [73H(2), 923:922]
          uint8_t io14_pull_up_down_resistance_selection: 2;  // [73H(4), 925:924]
          uint8_t io14_pull_up_down_selection: 1;             // [73H(6), 926:926]
        };
        uint8_t reg_73;
      };
      union {
        struct {
          uint8_t : 1;                  // [74H(0), 928:928]
          uint8_t io0_digital_input: 1; // [74H(1), 929:929]
          uint8_t io1_digital_input: 1; // [74H(2), 930:930]
          uint8_t io2_digital_input: 1; // [74H(3), 931:931]
          uint8_t io3_digital_input: 1; // [74H(4), 932:932]
          uint8_t io4_digital_input: 1; // [74H(5), 933:933]
          uint8_t io5_digital_input: 1; // [74H(6), 934:934]
          uint8_t io8_digital_input: 1; // [74H(7), 935:935]
        };
        uint8_t reg_74;
      };
      union {
        struct {
          uint8_t io9_digital_input: 1;   // [75H(0), 936:936]
          uint8_t io10_digital_input: 1;  // [75H(1), 937:937]
          uint8_t io11_digital_input: 1;  // [75H(2), 938:938]
          uint8_t io12_digital_input: 1;  // [75H(3), 939:939]
          uint8_t io13_digital_input: 1;  // [75H(4), 940:940]
          uint8_t io14_digital_input: 1;  // [75H(5), 941:941]
          uint8_t lut2_0_dff0_out: 1;     // [75H(6), 942:942]
          uint8_t lut2_1_dff1_out: 1;     // [75H(7), 943:943]
        };
        uint8_t reg_75;
      };
      union {
        struct {
          uint8_t lut2_2_dff2_out: 1; // [76H(0), 944:944]
          uint8_t lut2_3_pgen_out: 1; // [76H(1), 945:945]
          uint8_t lut3_0_dff3_out: 1; // [76H(2), 946:946]
          uint8_t lut3_1_dff4_out: 1; // [76H(3), 947:947]
          uint8_t lut3_2_dff5_out: 1; // [76H(4), 948:948]
          uint8_t lut3_3_dff6_out: 1; // [76H(5), 949:949]
          uint8_t lut3_4_dff7_out: 1; // [76H(6), 950:950]
          uint8_t lut3_5_dff8_out: 1; // [76H(7), 951:951]
        };
        uint8_t reg_76;
      };
      union {
        struct {
          uint8_t lut3_6_pipedly_ripp_cnt_out0: 1;    // [77H(0), 952:952]
          uint8_t pipedly_ripp_cnt_out1: 1;           // [77H(1), 953:953]
          uint8_t ripp_cnt_out2: 1;                   // [77H(2), 954:954]
          uint8_t edet_filter_out: 1;                 // [77H(3), 955:955]
          uint8_t prog_dly_edet_out: 1;               // [77H(4), 956:956]
          uint8_t multfunc_8bit_1_dly_cnt_out: 1;     // [77H(5), 957:957]
          uint8_t ckosc1_matrix_osc1_matrix_input: 1; // [77H(6), 958:958]
          uint8_t ckosc0_matrix_osc0_matrix_input: 1; // [77H(7), 959:959]
        };
        uint8_t reg_77;
      };
      union {
        struct {
          uint8_t ckosc2_matrix_osc2_matrix_input: 1; // [78H(0), 960:960]
          uint8_t multfunc_8bit_2_dly_cnt_out: 1;     // [78H(1), 961:961]
          uint8_t multfunc_8bit_3_dly_cnt_out: 1;     // [78H(2), 962:962]
          uint8_t multfunc_8bit_4_dly_cnt_out: 1;     // [78H(3), 963:963]
          uint8_t multfunc_8bit_5_dly_cnt_out: 1;     // [78H(4), 964:964]
          uint8_t multfunc_8bit_6_dly_cnt_out: 1;     // [78H(5), 965:965]
          uint8_t multfunc_8bit_7_dly_cnt_out: 1;     // [78H(6), 966:966]
          uint8_t multfunc_16bit_0_lut_dff_out: 1;    // [78H(7), 967:967]
        };
        uint8_t reg_78;
      };
      union {
        struct {
          uint8_t multfunc_8bit_1_lut_dff_out: 1;   // [79H(0), 968:968]
          uint8_t multfunc_8bit_2_lut_dff_out: 1;   // [79H(1), 969:969]
          uint8_t multfunc_8bit_3_lut_dff_out: 1;   // [79H(2), 970:970]
          uint8_t multfunc_8bit_4_lut_dff_out: 1;   // [79H(3), 971:971]
          uint8_t multfunc_8bit_5_lut_dff_out: 1;   // [79H(4), 972:972]
          uint8_t multfunc_8bit_6_lut_dff_out: 1;   // [79H(5), 973:973]
          uint8_t multfunc_8bit_7_lut_dff_out: 1;   // [79H(6), 974:974]
          uint8_t multfunc_16bit_0_dly_cnt_out: 1;  // [79H(7), 975:975]
        };
        uint8_t reg_79;
      };
      union {
        struct {
          uint8_t virtual_input_7: 1; // [7AH(0), 976:976]
          uint8_t virtual_input_6: 1; // [7AH(1), 977:977]
          uint8_t virtual_input_5: 1; // [7AH(2), 978:978]
          uint8_t virtual_input_4: 1; // [7AH(3), 979:979]
          uint8_t virtual_input_3: 1; // [7AH(4), 980:980]
          uint8_t virtual_input_2: 1; // [7AH(5), 981:981]
          uint8_t virtual_input_1: 1; // [7AH(6), 982:982]
          uint8_t virtual_input_0: 1; // [7AH(7), 983:983]
        };
        uint8_t reg_7a;
      };
      union {
        struct {
          uint8_t : 1;                      // [7BH(0), 984:984]
          uint8_t : 1;                      // [7BH(1), 985:985]
          uint8_t acmp0l_out: 1;            // [7BH(2), 986:986]
          uint8_t acmp1l_out: 1;            // [7BH(3), 987:987]
          uint8_t second_ckosc1_matrix: 1;  // [7BH(4), 988:988]
          uint8_t second_ckosc0_matrix: 1;  // [7BH(5), 989:989]
          uint8_t por_core: 1;              // [7BH(6), 990:990]
        };
        uint8_t reg_7b;
      };
      union {
        struct {
          uint8_t cnt0_counted_value_7_0: 8; // [7CH(0), 999:992]
        };
        uint8_t reg_7c;
      };
      union {
        struct {
          uint8_t cnt0_counted_value_15_8: 8; // [7DH(0), 1007:1000]
        };
        uint8_t reg_7d;
      };
      union {
        struct {
          uint8_t cnt2_counted_value: 8; // [7EH(0), 1015:1008]
        };
        uint8_t reg_7e;
      };
      union {
        struct {
          uint8_t cnt4_counted_value: 8; // [7FH(0), 1023:1016]
        };
        uint8_t reg_7f;
      };
      union {
        struct {
          uint8_t osc1_turn_on_by_register: 1;            // [80H(0), 1024:1024]
          uint8_t osc1_matrix_power_down_or_on_select: 1; // [80H(1), 1025:1025]
          uint8_t osc1_external_clock_source_enable: 1;   // [80H(2), 1026:1026]
          uint8_t osc1_post_divider_ration_control: 2;    // [80H(3), 1028:1027]
          uint8_t osc1_matrix_divider_ratio_control: 3;   // [80H(5), 1031:1029]
        };
        uint8_t reg_80;
      };
      union {
        struct {
          uint8_t osc2_turn_on_by_register: 1;            // [81H(0), 1032:1032]
          uint8_t osc2_matrix_power_down_or_on_select: 1; // [81H(1), 1033:1033]
          uint8_t osc2_external_clock_source_enable: 1;   // [81H(2), 1034:1034]
          uint8_t osc2_post_divider_ration_control: 2;    // [81H(3), 1036:1035]
          uint8_t osc2_matrix_divider_ratio_control: 3;   // [81H(5), 1039:1037]
        };
        uint8_t reg_81;
      };
      union {
        struct {
          uint8_t osc0_turn_on_by_register: 1;            // [82H(0), 1040:1040]
          uint8_t osc0_matrix_power_down_or_on_select: 1; // [82H(1), 1041:1041]
          uint8_t osc0_external_clock_source_enable: 1;   // [82H(2), 1042:1042]
          uint8_t osc0_post_divider_ration_control: 2;    // [82H(3), 1044:1043]
          uint8_t osc0_matrix_divider_ratio_control: 3;   // [82H(5), 1047:1045]
        };
        uint8_t reg_82;
      };
      union {
        struct {
          uint8_t : 1;                            // [83H(0), 1048:1048]
          uint8_t osc0_matrix_out_enable: 1;      // [83H(1), 1049:1049]
          uint8_t osc1_matrix_out_enable: 1;      // [83H(2), 1050:1050]
          uint8_t osc2_matrix_out_enable: 1;      // [83H(3), 1051:1051]
          uint8_t osc2_100_ns_startup_delay: 1;   // [83H(4), 1052:1052]
          uint8_t osc0_2nd_matrix_out_enable: 1;  // [83H(5), 1053:1053]
          uint8_t osc1_2nd_matrix_out_enable: 1;  // [83H(6), 1054:1054]
        };
        uint8_t reg_83;
      };
      union {
        struct {
          uint8_t osc1_2nd_matrix_input_matrix_divider_ratio_control: 3; // [84H(0), 1058:1056]
          uint8_t osc0_2nd_matrix_input_matrix_divider_ratio_control: 3; // [84H(3), 1061:1059]
        };
        uint8_t reg_84;
      };
      union {
        uint8_t reg_85;
      };
      union {
        uint8_t reg_86;
      };
      union {
        struct {
          uint8_t : 1;                  // [87H(0), 1080:1080]
          uint8_t : 1;                  // [87H(1), 1081:1081]
          uint8_t acmp0l_hysteresis: 2; // [87H(2), 1083:1082]
        };
        uint8_t reg_87;
      };
      union {
        struct {
          uint8_t acmp1l_hysteresis: 2;                                               // [88H(0), 1089:1088]
          uint8_t : 1;                                                                // [88H(2), 1090:1090]
          uint8_t : 1;                                                                // [88H(3), 1091:1091]
          uint8_t acmp1l_positive_input_come_from_acmp0ls_input_mux_output_enable: 1; // [88H(4), 1092:1092]
        };
        uint8_t reg_88;
      };
      union {
        uint8_t reg_89;
      };
      union {
        uint8_t reg_8a;
      };
      union {
        struct {
          uint8_t acmp0l_gain_divider: 2; // [8BH(0), 1113:1112]
          uint8_t acmp0l_vref: 6;         // [8BH(2), 1119:1114]
        };
        uint8_t reg_8b;
      };
      union {
        struct {
          uint8_t acmp1l_gain_divider: 2; // [8CH(0), 1121:1120]
          uint8_t acmp1l_vref: 6;         // [8CH(2), 1127:1122]
        };
        uint8_t reg_8c;
      };
      union {
        struct {
          uint8_t : 1;                      // [8DH(0), 1128:1128]
          uint8_t : 2;                      // [8DH(1), 1130:1129]
          uint8_t vref_output_op: 1;        // [8DH(3), 1131:1131]
          uint8_t vref0_input_selection: 2; // [8DH(4), 1133:1132]
        };
        uint8_t reg_8d;
      };
      union {
        struct {
          uint8_t : 1;            // [8EH(0), 1136:1136]
          uint8_t : 1;            // [8EH(1), 1137:1137]
          uint8_t : 1;            // [8EH(2), 1138:1138]
          uint8_t vref_out_pd: 1; // [8EH(3), 1139:1139]
        };
        uint8_t reg_8e;
      };
      union {
        uint8_t reg_8f;
      };
      union {
        struct {
          uint8_t lut2_0_dff0_setting: 4; // [90H(0), 1155:1152]
          uint8_t lut2_1_dff1_setting: 4; // [90H(4), 1159:1156]
        };
        uint8_t reg_90;
      };
      union {
        struct {
          uint8_t lut2_2_dff2_setting: 4;     // [91H(0), 1163:1160]
          uint8_t lut2_3_val_or_pgen_data: 4; // [91H(4), 1167:1164]
        };
        uint8_t reg_91;
      };
      union {
        struct {
          uint8_t pgen_data_7_0: 8; // [92H(0), 1175:1168]
        };
        uint8_t reg_92;
      };
      union {
        struct {
          uint8_t pgen_data_15_8: 8; // [93H(0), 1183:1176]
        };
        uint8_t reg_93;
      };
      union {
        struct {
          uint8_t lut3_0_dff3_setting: 8; // [94H(0), 1191:1184]
        };
        uint8_t reg_94;
      };
      union {
        struct {
          uint8_t lut3_1_dff4_setting: 8; // [95H(0), 1199:1192]
        };
        uint8_t reg_95;
      };
      union {
        struct {
          uint8_t lut3_2_dff5_setting: 8; // [96H(0), 1207:1200]
        };
        uint8_t reg_96;
      };
      union {
        struct {
          uint8_t lut3_3_dff6_setting: 8; // [97H(0), 1215:1208]
        };
        uint8_t reg_97;
      };
      union {
        struct {
          uint8_t lut3_4_dff7_setting: 8; // [98H(0), 1223:1216]
        };
        uint8_t reg_98;
      };
      union {
        struct {
          uint8_t lut3_5_dff8_setting: 8; // [99H(0), 1231:1224]
        };
        uint8_t reg_99;
      };
      union {
        struct {
          uint8_t lut2_0_or_dff0_select: 1; // [9AH(0), 1232:1232]
          uint8_t lut2_1_or_dff1_select: 1; // [9AH(1), 1233:1233]
          uint8_t lut2_2_or_dff2_select: 1; // [9AH(2), 1234:1234]
          uint8_t lut2_3_or_pgen_select: 1; // [9AH(3), 1235:1235]
          uint8_t lut3_0_or_dff3_select: 1; // [9AH(4), 1236:1236]
          uint8_t dff3_secondq_sel: 1;      // [9AH(5), 1237:1237]
          uint8_t lut3_1_or_dff4_select: 1; // [9AH(6), 1238:1238]
          uint8_t lut3_2_or_dff5_select: 1; // [9AH(7), 1239:1239]
        };
        uint8_t reg_9a;
      };
      union {
        struct {
          uint8_t lut3_3_or_dff6_select: 1;             // [9BH(0), 1240:1240]
          uint8_t lut3_4_or_dff7_select: 1;             // [9BH(1), 1241:1241]
          uint8_t lut3_5_or_dff8_select: 1;             // [9BH(2), 1242:1242]
          uint8_t filter_or_edge_detector_selection: 1; // [9BH(3), 1243:1243]
          uint8_t output_polarity_select: 1;            // [9BH(4), 1244:1244]
          uint8_t select_the_edge_mode: 2;              // [9BH(5), 1246:1245]
        };
        uint8_t reg_9b;
      };
      union {
        struct {
          uint8_t lut_value_or_pipe_delay_out_sel_or_nset_end_value: 8; // [9CH(0), 1255:1248]
        };
        uint8_t reg_9c;
      };
      union {
        struct {
          uint8_t pipe_delay_out1_polarity_select: 1;                           // [9DH(0), 1256:1256]
          uint8_t lut3_6_or_pipe_delay_select: 1;                               // [9DH(1), 1257:1257]
          uint8_t pipe_ripp_cnt_s: 1;                                           // [9DH(2), 1258:1258]
          uint8_t select_the_edge_mode_of_programmable_delay_edge_detector: 2;  // [9DH(3), 1260:1259]
          uint8_t delay_value_select_for_programmable_delay_edge_detector: 2;   // [9DH(5), 1262:1261]
        };
        uint8_t reg_9d;
      };
      union {
        uint8_t reg_9e;
      };
      union {
        uint8_t reg_9f;
      };
      union {
        struct {
          uint8_t : 1;                        // [A0H(0), 1280:1280]
          uint8_t : 1;                        // [A0H(1), 1281:1281]
          uint8_t : 1;                        // [A0H(2), 1282:1282]
          uint8_t : 1;                        // [A0H(3), 1283:1283]
          uint8_t : 1;                        // [A0H(4), 1284:1284]
          uint8_t : 1;                        // [A0H(5), 1285:1285]
          uint8_t : 1;                        // [A0H(6), 1286:1286]
          uint8_t fsm0_set_rst_selection: 1;  // [A0H(7), 1287:1287]
        };
        uint8_t reg_a0;
      };
      union {
        struct {
          uint8_t lut4_0_dff9_setting_7_0: 8; // [A1H(0), 1295:1288]
        };
        uint8_t reg_a1;
      };
      union {
        struct {
          uint8_t lut4_0_dff9_setting_15_8: 8; // [A2H(0), 1303:1296]
        };
        uint8_t reg_a2;
      };
      union {
        struct {
          uint8_t dly_cnt0_mode_selection: 2;       // [A3H(0), 1305:1304]
          uint8_t dly_cnt0_edge_mode_selection: 2;  // [A3H(2), 1307:1306]
          uint8_t dly_cnt0_clock_source_select: 4;  // [A3H(4), 1311:1308]
        };
        uint8_t reg_a3;
      };
      union {
        struct {
          uint8_t cnt0_output_pol_selection: 1;         // [A4H(0), 1312:1312]
          uint8_t cnt0_initial_value_selection: 2;      // [A4H(1), 1314:1313]
          uint8_t : 1;                                  // [A4H(3), 1315:1315]
          uint8_t : 1;                                  // [A4H(4), 1316:1316]
          uint8_t keep_signal_sync_selection: 1;        // [A4H(5), 1317:1317]
          uint8_t up_signal_sync_selection: 1;          // [A4H(6), 1318:1318]
          uint8_t cnt0_dly_edet_function_selection: 1;  // [A4H(7), 1319:1319]
        };
        uint8_t reg_a4;
      };
      union {
        struct {
          uint8_t reg_cnt0_data_7_0: 8; // [A5H(0), 1327:1320]
        };
        uint8_t reg_a5;
      };
      union {
        struct {
          uint8_t reg_cnt0_data_15_8: 8; // [A6H(0), 1335:1328]
        };
        uint8_t reg_a6;
      };
      union {
        struct {
          uint8_t cnt0_cnt_mode_sync_selection: 1;  // [A7H(0), 1336:1336]
          uint8_t : 1;                              // [A7H(1), 1337:1337]
          uint8_t : 1;                              // [A7H(2), 1338:1338]
          uint8_t : 1;                              // [A7H(3), 1339:1339]
          uint8_t : 1;                              // [A7H(4), 1340:1340]
          uint8_t : 1;                              // [A7H(5), 1341:1341]
          uint8_t cnt1_initial_value_selection: 2;  // [A7H(6), 1343:1342]
        };
        uint8_t reg_a7;
      };
      union {
        struct {
          uint8_t lut3_7_dff10_setting: 8; // [A8H(0), 1351:1344]
        };
        uint8_t reg_a8;
      };
      union {
        struct {
          uint8_t dly_cnt1_clock_source_select: 4;          // [A9H(0), 1355:1352]
          uint8_t cnt1_function_and_edge_mode_selection: 4; // [A9H(4), 1359:1356]
        };
        uint8_t reg_a9;
      };
      union {
        struct {
          uint8_t reg_cnt1_data: 8; // [AAH(0), 1367:1360]
        };
        uint8_t reg_aa;
      };
      union {
        struct {
          uint8_t cnt1_output_pol_selection: 1;         // [ABH(0), 1368:1368]
          uint8_t : 1;                                  // [ABH(1), 1369:1369]
          uint8_t cnt1_cnt_mode_sync_selection: 1;      // [ABH(2), 1370:1370]
          uint8_t cnt1_dly_edet_function_selection: 1;  // [ABH(3), 1371:1371]
          uint8_t : 4;                                  // [ABH(4), 1375:1372]
        };
        uint8_t reg_ab;
      };
      union {
        struct {
          uint8_t lut3_8_dff_11_setting: 8; // [ACH(0), 1383:1376]
        };
        uint8_t reg_ac;
      };
      union {
        struct {
          uint8_t dly_cnt2_clock_source_select: 4;          // [ADH(0), 1387:1384]
          uint8_t cnt2_function_and_edge_mode_selection: 4; // [ADH(4), 1391:1388]
        };
        uint8_t reg_ad;
      };
      union {
        struct {
          uint8_t cnt2_initial_value_selection: 2;      // [AEH(0), 1393:1392]
          uint8_t : 1;                                  // [AEH(2), 1394:1394]
          uint8_t cnt2_output_pol_selection: 1;         // [AEH(3), 1395:1395]
          uint8_t : 1;                                  // [AEH(4), 1396:1396]
          uint8_t cnt2_cnt_mode_sync_selection: 1;      // [AEH(5), 1397:1397]
          uint8_t cnt2_dly_edet_function_selection: 1;  // [AEH(6), 1398:1398]
        };
        uint8_t reg_ae;
      };
      union {
        struct {
          uint8_t reg_cnt2_data: 8; // [AFH(0), 1407:1400]
        };
        uint8_t reg_af;
      };
      union {
        struct {
          uint8_t : 1;                              // [B0H(0), 1408:1408]
          uint8_t : 1;                              // [B0H(1), 1409:1409]
          uint8_t : 1;                              // [B0H(2), 1410:1410]
          uint8_t : 1;                              // [B0H(3), 1411:1411]
          uint8_t : 1;                              // [B0H(4), 1412:1412]
          uint8_t : 1;                              // [B0H(5), 1413:1413]
          uint8_t cnt3_initial_value_selection: 2;  // [B0H(6), 1415:1414]
        };
        uint8_t reg_b0;
      };
      union {
        struct {
          uint8_t lut3_9_dff12_setting: 8; // [B1H(0), 1423:1416]
        };
        uint8_t reg_b1;
      };
      union {
        struct {
          uint8_t dly_cnt3_clock_source_select: 4;          // [B2H(0), 1427:1424]
          uint8_t cnt3_function_and_edge_mode_selection: 4; // [B2H(4), 1431:1428]
        };
        uint8_t reg_b2;
      };
      union {
        struct {
          uint8_t reg_cnt3_data: 8; // [B3H(0), 1439:1432]
        };
        uint8_t reg_b3;
      };
      union {
        struct {
          uint8_t cnt3_output_pol_selection: 1;         // [B4H(0), 1440:1440]
          uint8_t : 1;                                  // [B4H(1), 1441:1441]
          uint8_t cnt3_cnt_mode_sync_selection: 1;      // [B4H(2), 1442:1442]
          uint8_t cnt3_dly_edet_function_selection: 1;  // [B4H(3), 1443:1443]
        };
        uint8_t reg_b4;
      };
      union {
        struct {
          uint8_t lut3_dff_setting: 8; // [B5H(0), 1455:1448]
        };
        uint8_t reg_b5;
      };
      union {
        struct {
          uint8_t dly_cnt4_clock_source_select: 4;          // [B6H(0), 1459:1456]
          uint8_t cnt4_function_and_edge_mode_selection: 4; // [B6H(4), 1463:1460]
        };
        uint8_t reg_b6;
      };
      union {
        struct {
          uint8_t cnt4_initial_value_selection: 2;      // [B7H(0), 1465:1464]
          uint8_t : 1;                                  // [B7H(2), 1466:1466]
          uint8_t cnt4_output_pol_selection: 1;         // [B7H(3), 1467:1467]
          uint8_t : 1;                                  // [B7H(4), 1468:1468]
          uint8_t cnt4_cnt_mode_sync_selection: 1;      // [B7H(5), 1469:1469]
          uint8_t cnt4_dly_edet_function_selection: 1;  // [B7H(6), 1470:1470]
        };
        uint8_t reg_b7;
      };
      union {
        struct {
          uint8_t reg_cnt4_data: 8; // [B8H(0), 1479:1472]
        };
        uint8_t reg_b8;
      };
      union {
        struct {
          uint8_t : 1;                              // [B9H(0), 1480:1480]
          uint8_t : 1;                              // [B9H(1), 1481:1481]
          uint8_t : 1;                              // [B9H(2), 1482:1482]
          uint8_t : 1;                              // [B9H(3), 1483:1483]
          uint8_t : 1;                              // [B9H(4), 1484:1484]
          uint8_t : 1;                              // [B9H(5), 1485:1485]
          uint8_t cnt5_initial_value_selection: 2;  // [B9H(6), 1487:1486]
        };
        uint8_t reg_b9;
      };
      union {
        struct {
          uint8_t lut3_11_dff14_setting: 8; // [BAH(0), 1495:1488]
        };
        uint8_t reg_ba;
      };
      union {
        struct {
          uint8_t dly_cnt5_clock_source_select: 4;          // [BBH(0), 1499:1496]
          uint8_t cnt5_function_and_edge_mode_selection: 4; // [BBH(4), 1503:1500]
        };
        uint8_t reg_bb;
      };
      union {
        struct {
          uint8_t reg_cnt5_data: 8; // [BCH(0), 1511:1504]
        };
        uint8_t reg_bc;
      };
      union {
        struct {
          uint8_t cnt5_output_pol_selection: 1;         // [BDH(0), 1512:1512]
          uint8_t : 1;                                  // [BDH(1), 1513:1513]
          uint8_t cnt5_cnt_mode_sync_selection: 1;      // [BDH(2), 1514:1514]
          uint8_t cnt5_dly_edet_function_selection: 1;  // [BDH(3), 1515:1515]
        };
        uint8_t reg_bd;
      };
      union {
        struct {
          uint8_t lut3_12_dff15_setting: 8; // [BEH(0), 1527:1520]
        };
        uint8_t reg_be;
      };
      union {
        struct {
          uint8_t dly_cnt6_clock_source_select: 4;          // [BFH(0), 1531:1528]
          uint8_t cnt6_function_and_edge_mode_selection: 4; // [BFH(4), 1535:1532]
        };
        uint8_t reg_bf;
      };
      union {
        struct {
          uint8_t cnt6_initial_value_selection: 2;      // [C0H(0), 1537:1536]
          uint8_t : 1;                                  // [C0H(2), 1538:1538]
          uint8_t cnt6_output_pol_selection: 1;         // [C0H(3), 1539:1539]
          uint8_t : 1;                                  // [C0H(4), 1540:1540]
          uint8_t cnt6_cnt_mode_sync_selection: 1;      // [C0H(5), 1541:1541]
          uint8_t cnt6_dly_edet_function_selection: 1;  // [C0H(6), 1542:1542]
        };
        uint8_t reg_c0;
      };
      union {
        struct {
          uint8_t reg_cnt6_data: 8; // [C1H(0), 1551:1544]
        };
        uint8_t reg_c1;
      };
      union {
        struct {
          uint8_t : 5;                              // [C2H(0), 1556:1552]
          uint8_t cnt7_output_pol_selection: 1;     // [C2H(5), 1557:1557]
          uint8_t : 1;                              // [C2H(6), 1558:1558]
          uint8_t cnt7_cnt_mode_sync_selection: 1;  // [C2H(7), 1559:1559]
        };
        uint8_t reg_c2;
      };
      union {
        struct {
          uint8_t lut3_13_dff16_setting: 8; // [C3H(0), 1567:1560]
        };
        uint8_t reg_c3;
      };
      union {
        struct {
          uint8_t dly_cnt7_clock_source_select: 4;          // [C4H(0), 1571:1568]
          uint8_t cnt7_function_and_edge_mode_selection: 4; // [C4H(4), 1575:1572]
        };
        uint8_t reg_c4;
      };
      union {
        struct {
          uint8_t cnt7_initial_value_selection: 2;      // [C5H(0), 1577:1576]
          uint8_t cnt7_dly_edet_function_selection: 1;  // [C5H(2), 1578:1578]
        };
        uint8_t reg_c5;
      };
      union {
        struct {
          uint8_t reg_cnt7_data: 8; // [C6H(0), 1591:1584]
        };
        uint8_t reg_c6;
      };
      union {
        struct {
          uint8_t io0_i2c_output_expander_data: 1;    // [C7H(0), 1592:1592]
          uint8_t io0_i2c_output_expander_select: 1;  // [C7H(1), 1593:1593]
          uint8_t io5_i2c_output_expander_data: 1;    // [C7H(2), 1594:1594]
          uint8_t io5_i2c_output_expander_select: 1;  // [C7H(3), 1595:1595]
          uint8_t io6_i2c_output_expander_data: 1;    // [C7H(4), 1596:1596]
          uint8_t io6_i2c_output_expander_select: 1;  // [C7H(5), 1597:1597]
          uint8_t io9_i2c_output_expander_data: 1;    // [C7H(6), 1598:1598]
          uint8_t io9_i2c_output_expander_select: 1;  // [C7H(7), 1599:1599]
        };
        uint8_t reg_c7;
      };
      union {
        struct {
          uint8_t : 1;                                                                // [C8H(0), 1600:1600]
          uint8_t i2c_reset_bit_with_reloading_nvm_into_data_register_soft_reset: 1;  // [C8H(1), 1601:1601]
          uint8_t io_latching_enable_during_i2c_write_interface: 1;                   // [C8H(2), 1602:1602]
        };
        uint8_t reg_c8;
      };
      union {
        struct {
          uint8_t i2c_write_mask_bits: 8; // [C9H(0), 1615:1608]
        };
        uint8_t reg_c9;
      };
      union {
        struct {
          uint8_t i2c_slave_address: 4;           // [CAH(0), 1619:1616]
          uint8_t slave_address_selection_a4: 1;  // [CAH(4), 1620:1620]
          uint8_t slave_address_selection_a5: 1;  // [CAH(5), 1621:1621]
          uint8_t slave_address_selection_a6: 1;  // [CAH(6), 1622:1622]
          uint8_t slave_address_selection_a7: 1;  // [CAH(7), 1623:1623]
        };
        uint8_t reg_ca;
      };
      union {
        struct {
          uint8_t pattern_id_byte_0: 8; // [CBH(0), 1631:1624]
        };
        uint8_t reg_cb;
      };
      union {
        uint8_t reg_cc;
      };
      union {
        uint8_t reg_cd;
      };
      union {
        uint8_t reg_ce;
      };
      union {
        uint8_t reg_cf;
      };
      union {
        uint8_t reg_d0;
      };
      union {
        uint8_t reg_d1;
      };
      union {
        uint8_t reg_d2;
      };
      union {
        uint8_t reg_d3;
      };
      union {
        uint8_t reg_d4;
      };
      union {
        uint8_t reg_d5;
      };
      union {
        uint8_t reg_d6;
      };
      union {
        uint8_t reg_d7;
      };
      union {
        uint8_t reg_d8;
      };
      union {
        uint8_t reg_d9;
      };
      union {
        uint8_t reg_da;
      };
      union {
        uint8_t reg_db;
      };
      union {
        uint8_t reg_dc;
      };
      union {
        uint8_t reg_dd;
      };
      union {
        uint8_t reg_de;
      };
      union {
        uint8_t reg_df;
      };
      union {
        struct {
          uint8_t register_read_selection_bits: 2;  // [E0H(0), 1793:1792]
          uint8_t register_write_selection_bits: 2; // [E0H(2), 1795:1794]
        };
        uint8_t reg_e0;
      };
      union {
        struct {
          uint8_t nvm_configuration_selection_bits: 2; // [E1H(0), 1801:1800]
        };
        uint8_t reg_e1;
      };
      union {
        uint8_t reg_e2;
      };
      union {
        struct {
          uint8_t : 2;                                // [E2H(0), 1809:1808]
          uint8_t write_protect_register_enable: 1;   // [E2H(2), 1810:1810]
          uint8_t : 5;                                // [E2H(3), 1815:1811]
          uint8_t page_selection_for_erase_erseb: 5;  // [E3H(0), 1820:1816]
          uint8_t : 1;                                // [E3H(5), 1821:1821]
          uint8_t : 1;                                // [E3H(6), 1822:1822]
          uint8_t erase_enable: 1;                    // [E3H(7), 1823:1823]
        };
        uint8_t reg_e3;
      };
      union {
        struct {
          uint8_t protection_lock_bit_prl: 1; // [E4H(0), 1824:1824]
        };
        uint8_t reg_e4;
      };
      union {
        uint8_t reg_e5;
      };
      union {
        uint8_t reg_e6;
      };
      union {
        uint8_t reg_e7;
      };
      union {
        uint8_t reg_e8;
      };
      union {
        uint8_t reg_e9;
      };
      union {
        uint8_t reg_ea;
      };
      union {
        uint8_t reg_eb;
      };
      union {
        uint8_t reg_ec;
      };
      union {
        uint8_t reg_ed;
      };
      union {
        uint8_t reg_ee;
      };
      union {
        uint8_t reg_ef;
      };
      union {
        uint8_t reg_f0;
      };
      union {
        uint8_t reg_f1;
      };
      union {
        uint8_t reg_f2;
      };
      union {
        uint8_t reg_f3;
      };
      union {
        uint8_t reg_f4;
      };
      union {
        uint8_t reg_f5;
      };
      union {
        uint8_t reg_f6;
      };
      union {
        uint8_t reg_f7;
      };
      union {
        uint8_t reg_f8;
      };
      union {
        uint8_t reg_f9;
      };
      union {
        uint8_t reg_fa;
      };
      union {
        uint8_t reg_fb;
      };
      union {
        uint8_t reg_fc;
      };
      union {
        uint8_t reg_fd;
      };
      union {
        uint8_t reg_fe;
      };
      union {
        uint8_t reg_ff;
      };

    };
    uint8_t reg_data[256];
  };
} slg_register_t;

inline void debug_print_slg46826(const slg_register_t &slgReg) {
  Serial.println();

  Serial.printf("%3d(0x%02X) : [60H(0) 768:768(1)] io_fast_pull_up_down_enable\n", slgReg.io_fast_pull_up_down_enable, slgReg.io_fast_pull_up_down_enable);
  Serial.printf("%3d(0x%02X) : [60H(1) 769:769(1)] i2c_mode_selection\n", slgReg.i2c_mode_selection, slgReg.i2c_mode_selection);
  Serial.printf("%3d(0x%02X) : [61H(0) 777:776(2)] io0_input_mode_configuration\n", slgReg.io0_input_mode_configuration, slgReg.io0_input_mode_configuration);
  Serial.printf("%3d(0x%02X) : [61H(2) 779:778(2)] io0_output_mode_configuration\n", slgReg.io0_output_mode_configuration, slgReg.io0_output_mode_configuration);
  Serial.printf("%3d(0x%02X) : [61H(4) 781:780(2)] io0_pull_up_down_resistance_selection\n", slgReg.io0_pull_up_down_resistance_selection, slgReg.io0_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [61H(6) 782:782(1)] io0_pull_up_down_selection\n", slgReg.io0_pull_up_down_selection, slgReg.io0_pull_up_down_selection);
  Serial.printf("%3d(0x%02X) : [61H(7) 783:783(1)] io0_output_enable\n", slgReg.io0_output_enable, slgReg.io0_output_enable);
  Serial.printf("%3d(0x%02X) : [62H(0) 785:784(2)] io1_input_mode_configuration\n", slgReg.io1_input_mode_configuration, slgReg.io1_input_mode_configuration);
  Serial.printf("%3d(0x%02X) : [62H(2) 787:786(2)] io1_output_mode_configuration\n", slgReg.io1_output_mode_configuration, slgReg.io1_output_mode_configuration);
  Serial.printf("%3d(0x%02X) : [62H(4) 789:788(2)] io1_pull_up_down_resistance_selection\n", slgReg.io1_pull_up_down_resistance_selection, slgReg.io1_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [62H(6) 790:790(1)] io1_pull_up_down_selection\n", slgReg.io1_pull_up_down_selection, slgReg.io1_pull_up_down_selection);
  Serial.printf("%3d(0x%02X) : [64H(0) 801:800(2)] io2_input_mode_configuration\n", slgReg.io2_input_mode_configuration, slgReg.io2_input_mode_configuration);
  Serial.printf("%3d(0x%02X) : [64H(2) 803:802(2)] io2_output_mode_configuration\n", slgReg.io2_output_mode_configuration, slgReg.io2_output_mode_configuration);
  Serial.printf("%3d(0x%02X) : [64H(4) 805:804(2)] io2_pull_up_down_resistance_selection\n", slgReg.io2_pull_up_down_resistance_selection, slgReg.io2_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [64H(6) 806:806(1)] io2_pull_up_down_selection\n", slgReg.io2_pull_up_down_selection, slgReg.io2_pull_up_down_selection);
  Serial.printf("%3d(0x%02X) : [64H(7) 807:807(1)] io2_output_enable\n", slgReg.io2_output_enable, slgReg.io2_output_enable);
  Serial.printf("%3d(0x%02X) : [65H(0) 809:808(2)] io3_input_mode_configuration\n", slgReg.io3_input_mode_configuration, slgReg.io3_input_mode_configuration);
  Serial.printf("%3d(0x%02X) : [65H(2) 811:810(2)] io3_output_mode_configuration\n", slgReg.io3_output_mode_configuration, slgReg.io3_output_mode_configuration);
  Serial.printf("%3d(0x%02X) : [65H(4) 813:812(2)] io3_pull_up_down_resistance_selection\n", slgReg.io3_pull_up_down_resistance_selection, slgReg.io3_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [65H(6) 814:814(1)] io3_pull_up_down_selection\n", slgReg.io3_pull_up_down_selection, slgReg.io3_pull_up_down_selection);
  Serial.printf("%3d(0x%02X) : [65H(7) 815:815(1)] io3_output_enable\n", slgReg.io3_output_enable, slgReg.io3_output_enable);
  Serial.printf("%3d(0x%02X) : [66H(0) 817:816(2)] io4_input_mode_configuration\n", slgReg.io4_input_mode_configuration, slgReg.io4_input_mode_configuration);
  Serial.printf("%3d(0x%02X) : [66H(2) 819:818(2)] io4_output_mode_configuration\n", slgReg.io4_output_mode_configuration, slgReg.io4_output_mode_configuration);
  Serial.printf("%3d(0x%02X) : [66H(4) 821:820(2)] io4_pull_up_down_resistance_selection\n", slgReg.io4_pull_up_down_resistance_selection, slgReg.io4_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [66H(6) 822:822(1)] io4_pull_up_down_selection\n", slgReg.io4_pull_up_down_selection, slgReg.io4_pull_up_down_selection);
  Serial.printf("%3d(0x%02X) : [67H(0) 825:824(2)] io5_input_mode_configuration\n", slgReg.io5_input_mode_configuration, slgReg.io5_input_mode_configuration);
  Serial.printf("%3d(0x%02X) : [67H(2) 827:826(2)] io5_output_mode_configuration\n", slgReg.io5_output_mode_configuration, slgReg.io5_output_mode_configuration);
  Serial.printf("%3d(0x%02X) : [67H(4) 829:828(2)] io5_pull_up_down_resistance_selection\n", slgReg.io5_pull_up_down_resistance_selection, slgReg.io5_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [67H(6) 830:830(1)] io5_pull_up_down_selection\n", slgReg.io5_pull_up_down_selection, slgReg.io5_pull_up_down_selection);
  Serial.printf("%3d(0x%02X) : [68H(1) 834:833(2)] scl_input_mode_configuration\n", slgReg.scl_input_mode_configuration, slgReg.scl_input_mode_configuration);
  Serial.printf("%3d(0x%02X) : [68H(3) 836:835(2)] scl_pull_up_down_resistance_selection\n", slgReg.scl_pull_up_down_resistance_selection, slgReg.scl_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [69H(1) 842:841(2)] sda_input_mode_configuration\n", slgReg.sda_input_mode_configuration, slgReg.sda_input_mode_configuration);
  Serial.printf("%3d(0x%02X) : [69H(3) 844:843(2)] sda_pull_up_down_resistance_selection\n", slgReg.sda_pull_up_down_resistance_selection, slgReg.sda_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [6AH(2) 851:850(2)] io6_output_mode_configuration\n", slgReg.io6_output_mode_configuration, slgReg.io6_output_mode_configuration);
  Serial.printf("%3d(0x%02X) : [6AH(4) 853:852(2)] io6_pull_up_down_resistance_selection\n", slgReg.io6_pull_up_down_resistance_selection, slgReg.io6_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [6AH(6) 854:854(1)] io6_pull_up_down_selection\n", slgReg.io6_pull_up_down_selection, slgReg.io6_pull_up_down_selection);
  Serial.printf("%3d(0x%02X) : [6AH(7) 855:855(1)] io6_output_enable\n", slgReg.io6_output_enable, slgReg.io6_output_enable);
  Serial.printf("%3d(0x%02X) : [6BH(2) 859:858(2)] io7_output_mode_configuration\n", slgReg.io7_output_mode_configuration, slgReg.io7_output_mode_configuration);
  Serial.printf("%3d(0x%02X) : [6BH(4) 861:860(2)] io7_pull_up_down_resistance_selection\n", slgReg.io7_pull_up_down_resistance_selection, slgReg.io7_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [6BH(6) 862:862(1)] io7_pull_up_down_selection\n", slgReg.io7_pull_up_down_selection, slgReg.io7_pull_up_down_selection);
  Serial.printf("%3d(0x%02X) : [6BH(7) 863:863(1)] io7_output_enable\n", slgReg.io7_output_enable, slgReg.io7_output_enable);
  Serial.printf("%3d(0x%02X) : [6CH(0) 865:864(2)] io8_input_mode_configuration\n", slgReg.io8_input_mode_configuration, slgReg.io8_input_mode_configuration);
  Serial.printf("%3d(0x%02X) : [6CH(2) 867:866(2)] io8_output_mode_configuration\n", slgReg.io8_output_mode_configuration, slgReg.io8_output_mode_configuration);
  Serial.printf("%3d(0x%02X) : [6CH(4) 869:868(2)] io8_pull_up_down_resistance_selection\n", slgReg.io8_pull_up_down_resistance_selection, slgReg.io8_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [6CH(6) 870:870(1)] io8_pull_up_down_selection\n", slgReg.io8_pull_up_down_selection, slgReg.io8_pull_up_down_selection);
  Serial.printf("%3d(0x%02X) : [6EH(0) 881:880(2)] io9_input_mode_configuration\n", slgReg.io9_input_mode_configuration, slgReg.io9_input_mode_configuration);
  Serial.printf("%3d(0x%02X) : [6EH(2) 883:882(2)] io9_output_mode_configuration\n", slgReg.io9_output_mode_configuration, slgReg.io9_output_mode_configuration);
  Serial.printf("%3d(0x%02X) : [6EH(4) 885:884(2)] io9_pull_up_down_resistance_selection\n", slgReg.io9_pull_up_down_resistance_selection, slgReg.io9_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [6EH(6) 886:886(1)] io9_pull_up_down_selection\n", slgReg.io9_pull_up_down_selection, slgReg.io9_pull_up_down_selection);
  Serial.printf("%3d(0x%02X) : [6FH(0) 889:888(2)] io10_input_mode_configuration\n", slgReg.io10_input_mode_configuration, slgReg.io10_input_mode_configuration);
  Serial.printf("%3d(0x%02X) : [6FH(2) 891:890(2)] io10_output_mode_configuration\n", slgReg.io10_output_mode_configuration, slgReg.io10_output_mode_configuration);
  Serial.printf("%3d(0x%02X) : [6FH(4) 893:892(2)] io10_pull_up_down_resistance_selection\n", slgReg.io10_pull_up_down_resistance_selection, slgReg.io10_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [6FH(6) 894:894(1)] io10_pull_up_down_selection\n", slgReg.io10_pull_up_down_selection, slgReg.io10_pull_up_down_selection);
  Serial.printf("%3d(0x%02X) : [70H(0) 897:896(2)] io11_input_mode_configuration\n", slgReg.io11_input_mode_configuration, slgReg.io11_input_mode_configuration);
  Serial.printf("%3d(0x%02X) : [70H(2) 899:898(2)] io11_output_mode_configuration\n", slgReg.io11_output_mode_configuration, slgReg.io11_output_mode_configuration);
  Serial.printf("%3d(0x%02X) : [70H(4) 901:900(2)] io11_pull_up_down_resistance_selection\n", slgReg.io11_pull_up_down_resistance_selection, slgReg.io11_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [70H(6) 902:902(1)] io11_pull_up_down_selection\n", slgReg.io11_pull_up_down_selection, slgReg.io11_pull_up_down_selection);
  Serial.printf("%3d(0x%02X) : [71H(0) 905:904(2)] io12_input_mode_configuration\n", slgReg.io12_input_mode_configuration, slgReg.io12_input_mode_configuration);
  Serial.printf("%3d(0x%02X) : [71H(2) 907:906(2)] io12_output_mode_configuration\n", slgReg.io12_output_mode_configuration, slgReg.io12_output_mode_configuration);
  Serial.printf("%3d(0x%02X) : [71H(4) 909:908(2)] io12_pull_up_down_resistance_selection\n", slgReg.io12_pull_up_down_resistance_selection, slgReg.io12_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [71H(6) 910:910(1)] io12_pull_up_down_selection\n", slgReg.io12_pull_up_down_selection, slgReg.io12_pull_up_down_selection);
  Serial.printf("%3d(0x%02X) : [72H(0) 913:912(2)] io13_input_mode_configuration\n", slgReg.io13_input_mode_configuration, slgReg.io13_input_mode_configuration);
  Serial.printf("%3d(0x%02X) : [72H(2) 915:914(2)] io13_output_mode_configuration\n", slgReg.io13_output_mode_configuration, slgReg.io13_output_mode_configuration);
  Serial.printf("%3d(0x%02X) : [72H(4) 917:916(2)] io13_pull_up_down_resistance_selection\n", slgReg.io13_pull_up_down_resistance_selection, slgReg.io13_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [72H(6) 918:918(1)] io13_pull_up_down_selection\n", slgReg.io13_pull_up_down_selection, slgReg.io13_pull_up_down_selection);
  Serial.printf("%3d(0x%02X) : [73H(0) 921:920(2)] io14_input_mode_configuration\n", slgReg.io14_input_mode_configuration, slgReg.io14_input_mode_configuration);
  Serial.printf("%3d(0x%02X) : [73H(2) 923:922(2)] io14_output_mode_configuration\n", slgReg.io14_output_mode_configuration, slgReg.io14_output_mode_configuration);
  Serial.printf("%3d(0x%02X) : [73H(4) 925:924(2)] io14_pull_up_down_resistance_selection\n", slgReg.io14_pull_up_down_resistance_selection, slgReg.io14_pull_up_down_resistance_selection);
  Serial.printf("%3d(0x%02X) : [73H(6) 926:926(1)] io14_pull_up_down_selection\n", slgReg.io14_pull_up_down_selection, slgReg.io14_pull_up_down_selection);
  Serial.printf("%3d(0x%02X) : [74H(1) 929:929(1)] io0_digital_input\n", slgReg.io0_digital_input, slgReg.io0_digital_input);
  Serial.printf("%3d(0x%02X) : [74H(2) 930:930(1)] io1_digital_input\n", slgReg.io1_digital_input, slgReg.io1_digital_input);
  Serial.printf("%3d(0x%02X) : [74H(3) 931:931(1)] io2_digital_input\n", slgReg.io2_digital_input, slgReg.io2_digital_input);
  Serial.printf("%3d(0x%02X) : [74H(4) 932:932(1)] io3_digital_input\n", slgReg.io3_digital_input, slgReg.io3_digital_input);
  Serial.printf("%3d(0x%02X) : [74H(5) 933:933(1)] io4_digital_input\n", slgReg.io4_digital_input, slgReg.io4_digital_input);
  Serial.printf("%3d(0x%02X) : [74H(6) 934:934(1)] io5_digital_input\n", slgReg.io5_digital_input, slgReg.io5_digital_input);
  Serial.printf("%3d(0x%02X) : [74H(7) 935:935(1)] io8_digital_input\n", slgReg.io8_digital_input, slgReg.io8_digital_input);
  Serial.printf("%3d(0x%02X) : [75H(0) 936:936(1)] io9_digital_input\n", slgReg.io9_digital_input, slgReg.io9_digital_input);
  Serial.printf("%3d(0x%02X) : [75H(1) 937:937(1)] io10_digital_input\n", slgReg.io10_digital_input, slgReg.io10_digital_input);
  Serial.printf("%3d(0x%02X) : [75H(2) 938:938(1)] io11_digital_input\n", slgReg.io11_digital_input, slgReg.io11_digital_input);
  Serial.printf("%3d(0x%02X) : [75H(3) 939:939(1)] io12_digital_input\n", slgReg.io12_digital_input, slgReg.io12_digital_input);
  Serial.printf("%3d(0x%02X) : [75H(4) 940:940(1)] io13_digital_input\n", slgReg.io13_digital_input, slgReg.io13_digital_input);
  Serial.printf("%3d(0x%02X) : [75H(5) 941:941(1)] io14_digital_input\n", slgReg.io14_digital_input, slgReg.io14_digital_input);
  Serial.printf("%3d(0x%02X) : [75H(6) 942:942(1)] lut2_0_dff0_out\n", slgReg.lut2_0_dff0_out, slgReg.lut2_0_dff0_out);
  Serial.printf("%3d(0x%02X) : [75H(7) 943:943(1)] lut2_1_dff1_out\n", slgReg.lut2_1_dff1_out, slgReg.lut2_1_dff1_out);
  Serial.printf("%3d(0x%02X) : [76H(0) 944:944(1)] lut2_2_dff2_out\n", slgReg.lut2_2_dff2_out, slgReg.lut2_2_dff2_out);
  Serial.printf("%3d(0x%02X) : [76H(1) 945:945(1)] lut2_3_pgen_out\n", slgReg.lut2_3_pgen_out, slgReg.lut2_3_pgen_out);
  Serial.printf("%3d(0x%02X) : [76H(2) 946:946(1)] lut3_0_dff3_out\n", slgReg.lut3_0_dff3_out, slgReg.lut3_0_dff3_out);
  Serial.printf("%3d(0x%02X) : [76H(3) 947:947(1)] lut3_1_dff4_out\n", slgReg.lut3_1_dff4_out, slgReg.lut3_1_dff4_out);
  Serial.printf("%3d(0x%02X) : [76H(4) 948:948(1)] lut3_2_dff5_out\n", slgReg.lut3_2_dff5_out, slgReg.lut3_2_dff5_out);
  Serial.printf("%3d(0x%02X) : [76H(5) 949:949(1)] lut3_3_dff6_out\n", slgReg.lut3_3_dff6_out, slgReg.lut3_3_dff6_out);
  Serial.printf("%3d(0x%02X) : [76H(6) 950:950(1)] lut3_4_dff7_out\n", slgReg.lut3_4_dff7_out, slgReg.lut3_4_dff7_out);
  Serial.printf("%3d(0x%02X) : [76H(7) 951:951(1)] lut3_5_dff8_out\n", slgReg.lut3_5_dff8_out, slgReg.lut3_5_dff8_out);
  Serial.printf("%3d(0x%02X) : [77H(0) 952:952(1)] lut3_6_pipedly_ripp_cnt_out0\n", slgReg.lut3_6_pipedly_ripp_cnt_out0, slgReg.lut3_6_pipedly_ripp_cnt_out0);
  Serial.printf("%3d(0x%02X) : [77H(1) 953:953(1)] pipedly_ripp_cnt_out1\n", slgReg.pipedly_ripp_cnt_out1, slgReg.pipedly_ripp_cnt_out1);
  Serial.printf("%3d(0x%02X) : [77H(2) 954:954(1)] ripp_cnt_out2\n", slgReg.ripp_cnt_out2, slgReg.ripp_cnt_out2);
  Serial.printf("%3d(0x%02X) : [77H(3) 955:955(1)] edet_filter_out\n", slgReg.edet_filter_out, slgReg.edet_filter_out);
  Serial.printf("%3d(0x%02X) : [77H(4) 956:956(1)] prog_dly_edet_out\n", slgReg.prog_dly_edet_out, slgReg.prog_dly_edet_out);
  Serial.printf("%3d(0x%02X) : [77H(5) 957:957(1)] multfunc_8bit_1_dly_cnt_out\n", slgReg.multfunc_8bit_1_dly_cnt_out, slgReg.multfunc_8bit_1_dly_cnt_out);
  Serial.printf("%3d(0x%02X) : [77H(6) 958:958(1)] ckosc1_matrix_osc1_matrix_input\n", slgReg.ckosc1_matrix_osc1_matrix_input, slgReg.ckosc1_matrix_osc1_matrix_input);
  Serial.printf("%3d(0x%02X) : [77H(7) 959:959(1)] ckosc0_matrix_osc0_matrix_input\n", slgReg.ckosc0_matrix_osc0_matrix_input, slgReg.ckosc0_matrix_osc0_matrix_input);
  Serial.printf("%3d(0x%02X) : [78H(0) 960:960(1)] ckosc2_matrix_osc2_matrix_input\n", slgReg.ckosc2_matrix_osc2_matrix_input, slgReg.ckosc2_matrix_osc2_matrix_input);
  Serial.printf("%3d(0x%02X) : [78H(1) 961:961(1)] multfunc_8bit_2_dly_cnt_out\n", slgReg.multfunc_8bit_2_dly_cnt_out, slgReg.multfunc_8bit_2_dly_cnt_out);
  Serial.printf("%3d(0x%02X) : [78H(2) 962:962(1)] multfunc_8bit_3_dly_cnt_out\n", slgReg.multfunc_8bit_3_dly_cnt_out, slgReg.multfunc_8bit_3_dly_cnt_out);
  Serial.printf("%3d(0x%02X) : [78H(3) 963:963(1)] multfunc_8bit_4_dly_cnt_out\n", slgReg.multfunc_8bit_4_dly_cnt_out, slgReg.multfunc_8bit_4_dly_cnt_out);
  Serial.printf("%3d(0x%02X) : [78H(4) 964:964(1)] multfunc_8bit_5_dly_cnt_out\n", slgReg.multfunc_8bit_5_dly_cnt_out, slgReg.multfunc_8bit_5_dly_cnt_out);
  Serial.printf("%3d(0x%02X) : [78H(5) 965:965(1)] multfunc_8bit_6_dly_cnt_out\n", slgReg.multfunc_8bit_6_dly_cnt_out, slgReg.multfunc_8bit_6_dly_cnt_out);
  Serial.printf("%3d(0x%02X) : [78H(6) 966:966(1)] multfunc_8bit_7_dly_cnt_out\n", slgReg.multfunc_8bit_7_dly_cnt_out, slgReg.multfunc_8bit_7_dly_cnt_out);
  Serial.printf("%3d(0x%02X) : [78H(7) 967:967(1)] multfunc_16bit_0_lut_dff_out\n", slgReg.multfunc_16bit_0_lut_dff_out, slgReg.multfunc_16bit_0_lut_dff_out);
  Serial.printf("%3d(0x%02X) : [79H(0) 968:968(1)] multfunc_8bit_1_lut_dff_out\n", slgReg.multfunc_8bit_1_lut_dff_out, slgReg.multfunc_8bit_1_lut_dff_out);
  Serial.printf("%3d(0x%02X) : [79H(1) 969:969(1)] multfunc_8bit_2_lut_dff_out\n", slgReg.multfunc_8bit_2_lut_dff_out, slgReg.multfunc_8bit_2_lut_dff_out);
  Serial.printf("%3d(0x%02X) : [79H(2) 970:970(1)] multfunc_8bit_3_lut_dff_out\n", slgReg.multfunc_8bit_3_lut_dff_out, slgReg.multfunc_8bit_3_lut_dff_out);
  Serial.printf("%3d(0x%02X) : [79H(3) 971:971(1)] multfunc_8bit_4_lut_dff_out\n", slgReg.multfunc_8bit_4_lut_dff_out, slgReg.multfunc_8bit_4_lut_dff_out);
  Serial.printf("%3d(0x%02X) : [79H(4) 972:972(1)] multfunc_8bit_5_lut_dff_out\n", slgReg.multfunc_8bit_5_lut_dff_out, slgReg.multfunc_8bit_5_lut_dff_out);
  Serial.printf("%3d(0x%02X) : [79H(5) 973:973(1)] multfunc_8bit_6_lut_dff_out\n", slgReg.multfunc_8bit_6_lut_dff_out, slgReg.multfunc_8bit_6_lut_dff_out);
  Serial.printf("%3d(0x%02X) : [79H(6) 974:974(1)] multfunc_8bit_7_lut_dff_out\n", slgReg.multfunc_8bit_7_lut_dff_out, slgReg.multfunc_8bit_7_lut_dff_out);
  Serial.printf("%3d(0x%02X) : [79H(7) 975:975(1)] multfunc_16bit_0_dly_cnt_out\n", slgReg.multfunc_16bit_0_dly_cnt_out, slgReg.multfunc_16bit_0_dly_cnt_out);
  Serial.printf("%3d(0x%02X) : [7AH(0) 976:976(1)] virtual_input_7\n", slgReg.virtual_input_7, slgReg.virtual_input_7);
  Serial.printf("%3d(0x%02X) : [7AH(1) 977:977(1)] virtual_input_6\n", slgReg.virtual_input_6, slgReg.virtual_input_6);
  Serial.printf("%3d(0x%02X) : [7AH(2) 978:978(1)] virtual_input_5\n", slgReg.virtual_input_5, slgReg.virtual_input_5);
  Serial.printf("%3d(0x%02X) : [7AH(3) 979:979(1)] virtual_input_4\n", slgReg.virtual_input_4, slgReg.virtual_input_4);
  Serial.printf("%3d(0x%02X) : [7AH(4) 980:980(1)] virtual_input_3\n", slgReg.virtual_input_3, slgReg.virtual_input_3);
  Serial.printf("%3d(0x%02X) : [7AH(5) 981:981(1)] virtual_input_2\n", slgReg.virtual_input_2, slgReg.virtual_input_2);
  Serial.printf("%3d(0x%02X) : [7AH(6) 982:982(1)] virtual_input_1\n", slgReg.virtual_input_1, slgReg.virtual_input_1);
  Serial.printf("%3d(0x%02X) : [7AH(7) 983:983(1)] virtual_input_0\n", slgReg.virtual_input_0, slgReg.virtual_input_0);
  Serial.printf("%3d(0x%02X) : [7BH(2) 986:986(1)] acmp0l_out\n", slgReg.acmp0l_out, slgReg.acmp0l_out);
  Serial.printf("%3d(0x%02X) : [7BH(3) 987:987(1)] acmp1l_out\n", slgReg.acmp1l_out, slgReg.acmp1l_out);
  Serial.printf("%3d(0x%02X) : [7BH(4) 988:988(1)] second_ckosc1_matrix\n", slgReg.second_ckosc1_matrix, slgReg.second_ckosc1_matrix);
  Serial.printf("%3d(0x%02X) : [7BH(5) 989:989(1)] second_ckosc0_matrix\n", slgReg.second_ckosc0_matrix, slgReg.second_ckosc0_matrix);
  Serial.printf("%3d(0x%02X) : [7BH(6) 990:990(1)] por_core\n", slgReg.por_core, slgReg.por_core);
  Serial.printf("%3d(0x%02X) : [7CH(0) 999:992(8)] cnt0_counted_value_7_0\n", slgReg.cnt0_counted_value_7_0, slgReg.cnt0_counted_value_7_0);
  Serial.printf("%3d(0x%02X) : [7DH(0) 1007:1000(8)] cnt0_counted_value_15_8\n", slgReg.cnt0_counted_value_15_8, slgReg.cnt0_counted_value_15_8);
  Serial.printf("%3d(0x%02X) : [7EH(0) 1015:1008(8)] cnt2_counted_value\n", slgReg.cnt2_counted_value, slgReg.cnt2_counted_value);
  Serial.printf("%3d(0x%02X) : [7FH(0) 1023:1016(8)] cnt4_counted_value\n", slgReg.cnt4_counted_value, slgReg.cnt4_counted_value);
  Serial.printf("%3d(0x%02X) : [80H(0) 1024:1024(1)] osc1_turn_on_by_register\n", slgReg.osc1_turn_on_by_register, slgReg.osc1_turn_on_by_register);
  Serial.printf("%3d(0x%02X) : [80H(1) 1025:1025(1)] osc1_matrix_power_down_or_on_select\n", slgReg.osc1_matrix_power_down_or_on_select, slgReg.osc1_matrix_power_down_or_on_select);
  Serial.printf("%3d(0x%02X) : [80H(2) 1026:1026(1)] osc1_external_clock_source_enable\n", slgReg.osc1_external_clock_source_enable, slgReg.osc1_external_clock_source_enable);
  Serial.printf("%3d(0x%02X) : [80H(3) 1028:1027(2)] osc1_post_divider_ration_control\n", slgReg.osc1_post_divider_ration_control, slgReg.osc1_post_divider_ration_control);
  Serial.printf("%3d(0x%02X) : [80H(5) 1031:1029(3)] osc1_matrix_divider_ratio_control\n", slgReg.osc1_matrix_divider_ratio_control, slgReg.osc1_matrix_divider_ratio_control);
  Serial.printf("%3d(0x%02X) : [81H(0) 1032:1032(1)] osc2_turn_on_by_register\n", slgReg.osc2_turn_on_by_register, slgReg.osc2_turn_on_by_register);
  Serial.printf("%3d(0x%02X) : [81H(1) 1033:1033(1)] osc2_matrix_power_down_or_on_select\n", slgReg.osc2_matrix_power_down_or_on_select, slgReg.osc2_matrix_power_down_or_on_select);
  Serial.printf("%3d(0x%02X) : [81H(2) 1034:1034(1)] osc2_external_clock_source_enable\n", slgReg.osc2_external_clock_source_enable, slgReg.osc2_external_clock_source_enable);
  Serial.printf("%3d(0x%02X) : [81H(3) 1036:1035(2)] osc2_post_divider_ration_control\n", slgReg.osc2_post_divider_ration_control, slgReg.osc2_post_divider_ration_control);
  Serial.printf("%3d(0x%02X) : [81H(5) 1039:1037(3)] osc2_matrix_divider_ratio_control\n", slgReg.osc2_matrix_divider_ratio_control, slgReg.osc2_matrix_divider_ratio_control);
  Serial.printf("%3d(0x%02X) : [82H(0) 1040:1040(1)] osc0_turn_on_by_register\n", slgReg.osc0_turn_on_by_register, slgReg.osc0_turn_on_by_register);
  Serial.printf("%3d(0x%02X) : [82H(1) 1041:1041(1)] osc0_matrix_power_down_or_on_select\n", slgReg.osc0_matrix_power_down_or_on_select, slgReg.osc0_matrix_power_down_or_on_select);
  Serial.printf("%3d(0x%02X) : [82H(2) 1042:1042(1)] osc0_external_clock_source_enable\n", slgReg.osc0_external_clock_source_enable, slgReg.osc0_external_clock_source_enable);
  Serial.printf("%3d(0x%02X) : [82H(3) 1044:1043(2)] osc0_post_divider_ration_control\n", slgReg.osc0_post_divider_ration_control, slgReg.osc0_post_divider_ration_control);
  Serial.printf("%3d(0x%02X) : [82H(5) 1047:1045(3)] osc0_matrix_divider_ratio_control\n", slgReg.osc0_matrix_divider_ratio_control, slgReg.osc0_matrix_divider_ratio_control);
  Serial.printf("%3d(0x%02X) : [83H(1) 1049:1049(1)] osc0_matrix_out_enable\n", slgReg.osc0_matrix_out_enable, slgReg.osc0_matrix_out_enable);
  Serial.printf("%3d(0x%02X) : [83H(2) 1050:1050(1)] osc1_matrix_out_enable\n", slgReg.osc1_matrix_out_enable, slgReg.osc1_matrix_out_enable);
  Serial.printf("%3d(0x%02X) : [83H(3) 1051:1051(1)] osc2_matrix_out_enable\n", slgReg.osc2_matrix_out_enable, slgReg.osc2_matrix_out_enable);
  Serial.printf("%3d(0x%02X) : [83H(4) 1052:1052(1)] osc2_100_ns_startup_delay\n", slgReg.osc2_100_ns_startup_delay, slgReg.osc2_100_ns_startup_delay);
  Serial.printf("%3d(0x%02X) : [83H(5) 1053:1053(1)] osc0_2nd_matrix_out_enable\n", slgReg.osc0_2nd_matrix_out_enable, slgReg.osc0_2nd_matrix_out_enable);
  Serial.printf("%3d(0x%02X) : [83H(6) 1054:1054(1)] osc1_2nd_matrix_out_enable\n", slgReg.osc1_2nd_matrix_out_enable, slgReg.osc1_2nd_matrix_out_enable);
  Serial.printf("%3d(0x%02X) : [84H(0) 1058:1056(3)] osc1_2nd_matrix_input_matrix_divider_ratio_control\n", slgReg.osc1_2nd_matrix_input_matrix_divider_ratio_control, slgReg.osc1_2nd_matrix_input_matrix_divider_ratio_control);
  Serial.printf("%3d(0x%02X) : [84H(3) 1061:1059(3)] osc0_2nd_matrix_input_matrix_divider_ratio_control\n", slgReg.osc0_2nd_matrix_input_matrix_divider_ratio_control, slgReg.osc0_2nd_matrix_input_matrix_divider_ratio_control);
  Serial.printf("%3d(0x%02X) : [87H(2) 1083:1082(2)] acmp0l_hysteresis\n", slgReg.acmp0l_hysteresis, slgReg.acmp0l_hysteresis);
  Serial.printf("%3d(0x%02X) : [88H(0) 1089:1088(2)] acmp1l_hysteresis\n", slgReg.acmp1l_hysteresis, slgReg.acmp1l_hysteresis);
  Serial.printf("%3d(0x%02X) : [88H(4) 1092:1092(1)] acmp1l_positive_input_come_from_acmp0ls_input_mux_output_enable\n", slgReg.acmp1l_positive_input_come_from_acmp0ls_input_mux_output_enable, slgReg.acmp1l_positive_input_come_from_acmp0ls_input_mux_output_enable);
  Serial.printf("%3d(0x%02X) : [8BH(0) 1113:1112(2)] acmp0l_gain_divider\n", slgReg.acmp0l_gain_divider, slgReg.acmp0l_gain_divider);
  Serial.printf("%3d(0x%02X) : [8BH(2) 1119:1114(6)] acmp0l_vref\n", slgReg.acmp0l_vref, slgReg.acmp0l_vref);
  Serial.printf("%3d(0x%02X) : [8CH(0) 1121:1120(2)] acmp1l_gain_divider\n", slgReg.acmp1l_gain_divider, slgReg.acmp1l_gain_divider);
  Serial.printf("%3d(0x%02X) : [8CH(2) 1127:1122(6)] acmp1l_vref\n", slgReg.acmp1l_vref, slgReg.acmp1l_vref);
  Serial.printf("%3d(0x%02X) : [8DH(3) 1131:1131(1)] vref_output_op\n", slgReg.vref_output_op, slgReg.vref_output_op);
  Serial.printf("%3d(0x%02X) : [8DH(4) 1133:1132(2)] vref0_input_selection\n", slgReg.vref0_input_selection, slgReg.vref0_input_selection);
  Serial.printf("%3d(0x%02X) : [8EH(3) 1139:1139(1)] vref_out_pd\n", slgReg.vref_out_pd, slgReg.vref_out_pd);
  Serial.printf("%3d(0x%02X) : [90H(0) 1155:1152(4)] lut2_0_dff0_setting\n", slgReg.lut2_0_dff0_setting, slgReg.lut2_0_dff0_setting);
  Serial.printf("%3d(0x%02X) : [90H(4) 1159:1156(4)] lut2_1_dff1_setting\n", slgReg.lut2_1_dff1_setting, slgReg.lut2_1_dff1_setting);
  Serial.printf("%3d(0x%02X) : [91H(0) 1163:1160(4)] lut2_2_dff2_setting\n", slgReg.lut2_2_dff2_setting, slgReg.lut2_2_dff2_setting);
  Serial.printf("%3d(0x%02X) : [91H(4) 1167:1164(4)] lut2_3_val_or_pgen_data\n", slgReg.lut2_3_val_or_pgen_data, slgReg.lut2_3_val_or_pgen_data);
  Serial.printf("%3d(0x%02X) : [92H(0) 1175:1168(8)] pgen_data_7_0\n", slgReg.pgen_data_7_0, slgReg.pgen_data_7_0);
  Serial.printf("%3d(0x%02X) : [93H(0) 1183:1176(8)] pgen_data_15_8\n", slgReg.pgen_data_15_8, slgReg.pgen_data_15_8);
  Serial.printf("%3d(0x%02X) : [94H(0) 1191:1184(8)] lut3_0_dff3_setting\n", slgReg.lut3_0_dff3_setting, slgReg.lut3_0_dff3_setting);
  Serial.printf("%3d(0x%02X) : [95H(0) 1199:1192(8)] lut3_1_dff4_setting\n", slgReg.lut3_1_dff4_setting, slgReg.lut3_1_dff4_setting);
  Serial.printf("%3d(0x%02X) : [96H(0) 1207:1200(8)] lut3_2_dff5_setting\n", slgReg.lut3_2_dff5_setting, slgReg.lut3_2_dff5_setting);
  Serial.printf("%3d(0x%02X) : [97H(0) 1215:1208(8)] lut3_3_dff6_setting\n", slgReg.lut3_3_dff6_setting, slgReg.lut3_3_dff6_setting);
  Serial.printf("%3d(0x%02X) : [98H(0) 1223:1216(8)] lut3_4_dff7_setting\n", slgReg.lut3_4_dff7_setting, slgReg.lut3_4_dff7_setting);
  Serial.printf("%3d(0x%02X) : [99H(0) 1231:1224(8)] lut3_5_dff8_setting\n", slgReg.lut3_5_dff8_setting, slgReg.lut3_5_dff8_setting);
  Serial.printf("%3d(0x%02X) : [9AH(0) 1232:1232(1)] lut2_0_or_dff0_select\n", slgReg.lut2_0_or_dff0_select, slgReg.lut2_0_or_dff0_select);
  Serial.printf("%3d(0x%02X) : [9AH(1) 1233:1233(1)] lut2_1_or_dff1_select\n", slgReg.lut2_1_or_dff1_select, slgReg.lut2_1_or_dff1_select);
  Serial.printf("%3d(0x%02X) : [9AH(2) 1234:1234(1)] lut2_2_or_dff2_select\n", slgReg.lut2_2_or_dff2_select, slgReg.lut2_2_or_dff2_select);
  Serial.printf("%3d(0x%02X) : [9AH(3) 1235:1235(1)] lut2_3_or_pgen_select\n", slgReg.lut2_3_or_pgen_select, slgReg.lut2_3_or_pgen_select);
  Serial.printf("%3d(0x%02X) : [9AH(4) 1236:1236(1)] lut3_0_or_dff3_select\n", slgReg.lut3_0_or_dff3_select, slgReg.lut3_0_or_dff3_select);
  Serial.printf("%3d(0x%02X) : [9AH(5) 1237:1237(1)] dff3_secondq_sel\n", slgReg.dff3_secondq_sel, slgReg.dff3_secondq_sel);
  Serial.printf("%3d(0x%02X) : [9AH(6) 1238:1238(1)] lut3_1_or_dff4_select\n", slgReg.lut3_1_or_dff4_select, slgReg.lut3_1_or_dff4_select);
  Serial.printf("%3d(0x%02X) : [9AH(7) 1239:1239(1)] lut3_2_or_dff5_select\n", slgReg.lut3_2_or_dff5_select, slgReg.lut3_2_or_dff5_select);
  Serial.printf("%3d(0x%02X) : [9BH(0) 1240:1240(1)] lut3_3_or_dff6_select\n", slgReg.lut3_3_or_dff6_select, slgReg.lut3_3_or_dff6_select);
  Serial.printf("%3d(0x%02X) : [9BH(1) 1241:1241(1)] lut3_4_or_dff7_select\n", slgReg.lut3_4_or_dff7_select, slgReg.lut3_4_or_dff7_select);
  Serial.printf("%3d(0x%02X) : [9BH(2) 1242:1242(1)] lut3_5_or_dff8_select\n", slgReg.lut3_5_or_dff8_select, slgReg.lut3_5_or_dff8_select);
  Serial.printf("%3d(0x%02X) : [9BH(3) 1243:1243(1)] filter_or_edge_detector_selection\n", slgReg.filter_or_edge_detector_selection, slgReg.filter_or_edge_detector_selection);
  Serial.printf("%3d(0x%02X) : [9BH(4) 1244:1244(1)] output_polarity_select\n", slgReg.output_polarity_select, slgReg.output_polarity_select);
  Serial.printf("%3d(0x%02X) : [9BH(5) 1246:1245(2)] select_the_edge_mode\n", slgReg.select_the_edge_mode, slgReg.select_the_edge_mode);
  Serial.printf("%3d(0x%02X) : [9CH(0) 1255:1248(8)] lut_value_or_pipe_delay_out_sel_or_nset_end_value\n", slgReg.lut_value_or_pipe_delay_out_sel_or_nset_end_value, slgReg.lut_value_or_pipe_delay_out_sel_or_nset_end_value);
  Serial.printf("%3d(0x%02X) : [9DH(0) 1256:1256(1)] pipe_delay_out1_polarity_select\n", slgReg.pipe_delay_out1_polarity_select, slgReg.pipe_delay_out1_polarity_select);
  Serial.printf("%3d(0x%02X) : [9DH(1) 1257:1257(1)] lut3_6_or_pipe_delay_select\n", slgReg.lut3_6_or_pipe_delay_select, slgReg.lut3_6_or_pipe_delay_select);
  Serial.printf("%3d(0x%02X) : [9DH(2) 1258:1258(1)] pipe_ripp_cnt_s\n", slgReg.pipe_ripp_cnt_s, slgReg.pipe_ripp_cnt_s);
  Serial.printf("%3d(0x%02X) : [9DH(3) 1260:1259(2)] select_the_edge_mode_of_programmable_delay_edge_detector\n", slgReg.select_the_edge_mode_of_programmable_delay_edge_detector, slgReg.select_the_edge_mode_of_programmable_delay_edge_detector);
  Serial.printf("%3d(0x%02X) : [9DH(5) 1262:1261(2)] delay_value_select_for_programmable_delay_edge_detector\n", slgReg.delay_value_select_for_programmable_delay_edge_detector, slgReg.delay_value_select_for_programmable_delay_edge_detector);
  Serial.printf("%3d(0x%02X) : [A0H(7) 1287:1287(1)] fsm0_set_rst_selection\n", slgReg.fsm0_set_rst_selection, slgReg.fsm0_set_rst_selection);
  Serial.printf("%3d(0x%02X) : [A1H(0) 1295:1288(8)] lut4_0_dff9_setting_7_0\n", slgReg.lut4_0_dff9_setting_7_0, slgReg.lut4_0_dff9_setting_7_0);
  Serial.printf("%3d(0x%02X) : [A2H(0) 1303:1296(8)] lut4_0_dff9_setting_15_8\n", slgReg.lut4_0_dff9_setting_15_8, slgReg.lut4_0_dff9_setting_15_8);
  Serial.printf("%3d(0x%02X) : [A3H(0) 1305:1304(2)] dly_cnt0_mode_selection\n", slgReg.dly_cnt0_mode_selection, slgReg.dly_cnt0_mode_selection);
  Serial.printf("%3d(0x%02X) : [A3H(2) 1307:1306(2)] dly_cnt0_edge_mode_selection\n", slgReg.dly_cnt0_edge_mode_selection, slgReg.dly_cnt0_edge_mode_selection);
  Serial.printf("%3d(0x%02X) : [A3H(4) 1311:1308(4)] dly_cnt0_clock_source_select\n", slgReg.dly_cnt0_clock_source_select, slgReg.dly_cnt0_clock_source_select);
  Serial.printf("%3d(0x%02X) : [A4H(0) 1312:1312(1)] cnt0_output_pol_selection\n", slgReg.cnt0_output_pol_selection, slgReg.cnt0_output_pol_selection);
  Serial.printf("%3d(0x%02X) : [A4H(1) 1314:1313(2)] cnt0_initial_value_selection\n", slgReg.cnt0_initial_value_selection, slgReg.cnt0_initial_value_selection);
  Serial.printf("%3d(0x%02X) : [A4H(5) 1317:1317(1)] keep_signal_sync_selection\n", slgReg.keep_signal_sync_selection, slgReg.keep_signal_sync_selection);
  Serial.printf("%3d(0x%02X) : [A4H(6) 1318:1318(1)] up_signal_sync_selection\n", slgReg.up_signal_sync_selection, slgReg.up_signal_sync_selection);
  Serial.printf("%3d(0x%02X) : [A4H(7) 1319:1319(1)] cnt0_dly_edet_function_selection\n", slgReg.cnt0_dly_edet_function_selection, slgReg.cnt0_dly_edet_function_selection);
  Serial.printf("%3d(0x%02X) : [A5H(0) 1327:1320(8)] reg_cnt0_data_7_0\n", slgReg.reg_cnt0_data_7_0, slgReg.reg_cnt0_data_7_0);
  Serial.printf("%3d(0x%02X) : [A6H(0) 1335:1328(8)] reg_cnt0_data_15_8\n", slgReg.reg_cnt0_data_15_8, slgReg.reg_cnt0_data_15_8);
  Serial.printf("%3d(0x%02X) : [A7H(0) 1336:1336(1)] cnt0_cnt_mode_sync_selection\n", slgReg.cnt0_cnt_mode_sync_selection, slgReg.cnt0_cnt_mode_sync_selection);
  Serial.printf("%3d(0x%02X) : [A7H(6) 1343:1342(2)] cnt1_initial_value_selection\n", slgReg.cnt1_initial_value_selection, slgReg.cnt1_initial_value_selection);
  Serial.printf("%3d(0x%02X) : [A8H(0) 1351:1344(8)] lut3_7_dff10_setting\n", slgReg.lut3_7_dff10_setting, slgReg.lut3_7_dff10_setting);
  Serial.printf("%3d(0x%02X) : [A9H(0) 1355:1352(4)] dly_cnt1_clock_source_select\n", slgReg.dly_cnt1_clock_source_select, slgReg.dly_cnt1_clock_source_select);
  Serial.printf("%3d(0x%02X) : [A9H(4) 1359:1356(4)] cnt1_function_and_edge_mode_selection\n", slgReg.cnt1_function_and_edge_mode_selection, slgReg.cnt1_function_and_edge_mode_selection);
  Serial.printf("%3d(0x%02X) : [AAH(0) 1367:1360(8)] reg_cnt1_data\n", slgReg.reg_cnt1_data, slgReg.reg_cnt1_data);
  Serial.printf("%3d(0x%02X) : [ABH(0) 1368:1368(1)] cnt1_output_pol_selection\n", slgReg.cnt1_output_pol_selection, slgReg.cnt1_output_pol_selection);
  Serial.printf("%3d(0x%02X) : [ABH(2) 1370:1370(1)] cnt1_cnt_mode_sync_selection\n", slgReg.cnt1_cnt_mode_sync_selection, slgReg.cnt1_cnt_mode_sync_selection);
  Serial.printf("%3d(0x%02X) : [ABH(3) 1371:1371(1)] cnt1_dly_edet_function_selection\n", slgReg.cnt1_dly_edet_function_selection, slgReg.cnt1_dly_edet_function_selection);
  Serial.printf("%3d(0x%02X) : [ACH(0) 1383:1376(8)] lut3_8_dff_11_setting\n", slgReg.lut3_8_dff_11_setting, slgReg.lut3_8_dff_11_setting);
  Serial.printf("%3d(0x%02X) : [ADH(0) 1387:1384(4)] dly_cnt2_clock_source_select\n", slgReg.dly_cnt2_clock_source_select, slgReg.dly_cnt2_clock_source_select);
  Serial.printf("%3d(0x%02X) : [ADH(4) 1391:1388(4)] cnt2_function_and_edge_mode_selection\n", slgReg.cnt2_function_and_edge_mode_selection, slgReg.cnt2_function_and_edge_mode_selection);
  Serial.printf("%3d(0x%02X) : [AEH(0) 1393:1392(2)] cnt2_initial_value_selection\n", slgReg.cnt2_initial_value_selection, slgReg.cnt2_initial_value_selection);
  Serial.printf("%3d(0x%02X) : [AEH(3) 1395:1395(1)] cnt2_output_pol_selection\n", slgReg.cnt2_output_pol_selection, slgReg.cnt2_output_pol_selection);
  Serial.printf("%3d(0x%02X) : [AEH(5) 1397:1397(1)] cnt2_cnt_mode_sync_selection\n", slgReg.cnt2_cnt_mode_sync_selection, slgReg.cnt2_cnt_mode_sync_selection);
  Serial.printf("%3d(0x%02X) : [AEH(6) 1398:1398(1)] cnt2_dly_edet_function_selection\n", slgReg.cnt2_dly_edet_function_selection, slgReg.cnt2_dly_edet_function_selection);
  Serial.printf("%3d(0x%02X) : [AFH(0) 1407:1400(8)] reg_cnt2_data\n", slgReg.reg_cnt2_data, slgReg.reg_cnt2_data);
  Serial.printf("%3d(0x%02X) : [B0H(6) 1415:1414(2)] cnt3_initial_value_selection\n", slgReg.cnt3_initial_value_selection, slgReg.cnt3_initial_value_selection);
  Serial.printf("%3d(0x%02X) : [B1H(0) 1423:1416(8)] lut3_9_dff12_setting\n", slgReg.lut3_9_dff12_setting, slgReg.lut3_9_dff12_setting);
  Serial.printf("%3d(0x%02X) : [B2H(0) 1427:1424(4)] dly_cnt3_clock_source_select\n", slgReg.dly_cnt3_clock_source_select, slgReg.dly_cnt3_clock_source_select);
  Serial.printf("%3d(0x%02X) : [B2H(4) 1431:1428(4)] cnt3_function_and_edge_mode_selection\n", slgReg.cnt3_function_and_edge_mode_selection, slgReg.cnt3_function_and_edge_mode_selection);
  Serial.printf("%3d(0x%02X) : [B3H(0) 1439:1432(8)] reg_cnt3_data\n", slgReg.reg_cnt3_data, slgReg.reg_cnt3_data);
  Serial.printf("%3d(0x%02X) : [B4H(0) 1440:1440(1)] cnt3_output_pol_selection\n", slgReg.cnt3_output_pol_selection, slgReg.cnt3_output_pol_selection);
  Serial.printf("%3d(0x%02X) : [B4H(2) 1442:1442(1)] cnt3_cnt_mode_sync_selection\n", slgReg.cnt3_cnt_mode_sync_selection, slgReg.cnt3_cnt_mode_sync_selection);
  Serial.printf("%3d(0x%02X) : [B4H(3) 1443:1443(1)] cnt3_dly_edet_function_selection\n", slgReg.cnt3_dly_edet_function_selection, slgReg.cnt3_dly_edet_function_selection);
  Serial.printf("%3d(0x%02X) : [B5H(0) 1455:1448(8)] lut3_dff_setting\n", slgReg.lut3_dff_setting, slgReg.lut3_dff_setting);
  Serial.printf("%3d(0x%02X) : [B6H(0) 1459:1456(4)] dly_cnt4_clock_source_select\n", slgReg.dly_cnt4_clock_source_select, slgReg.dly_cnt4_clock_source_select);
  Serial.printf("%3d(0x%02X) : [B6H(4) 1463:1460(4)] cnt4_function_and_edge_mode_selection\n", slgReg.cnt4_function_and_edge_mode_selection, slgReg.cnt4_function_and_edge_mode_selection);
  Serial.printf("%3d(0x%02X) : [B7H(0) 1465:1464(2)] cnt4_initial_value_selection\n", slgReg.cnt4_initial_value_selection, slgReg.cnt4_initial_value_selection);
  Serial.printf("%3d(0x%02X) : [B7H(3) 1467:1467(1)] cnt4_output_pol_selection\n", slgReg.cnt4_output_pol_selection, slgReg.cnt4_output_pol_selection);
  Serial.printf("%3d(0x%02X) : [B7H(5) 1469:1469(1)] cnt4_cnt_mode_sync_selection\n", slgReg.cnt4_cnt_mode_sync_selection, slgReg.cnt4_cnt_mode_sync_selection);
  Serial.printf("%3d(0x%02X) : [B7H(6) 1470:1470(1)] cnt4_dly_edet_function_selection\n", slgReg.cnt4_dly_edet_function_selection, slgReg.cnt4_dly_edet_function_selection);
  Serial.printf("%3d(0x%02X) : [B8H(0) 1479:1472(8)] reg_cnt4_data\n", slgReg.reg_cnt4_data, slgReg.reg_cnt4_data);
  Serial.printf("%3d(0x%02X) : [B9H(6) 1487:1486(2)] cnt5_initial_value_selection\n", slgReg.cnt5_initial_value_selection, slgReg.cnt5_initial_value_selection);
  Serial.printf("%3d(0x%02X) : [BAH(0) 1495:1488(8)] lut3_11_dff14_setting\n", slgReg.lut3_11_dff14_setting, slgReg.lut3_11_dff14_setting);
  Serial.printf("%3d(0x%02X) : [BBH(0) 1499:1496(4)] dly_cnt5_clock_source_select\n", slgReg.dly_cnt5_clock_source_select, slgReg.dly_cnt5_clock_source_select);
  Serial.printf("%3d(0x%02X) : [BBH(4) 1503:1500(4)] cnt5_function_and_edge_mode_selection\n", slgReg.cnt5_function_and_edge_mode_selection, slgReg.cnt5_function_and_edge_mode_selection);
  Serial.printf("%3d(0x%02X) : [BCH(0) 1511:1504(8)] reg_cnt5_data\n", slgReg.reg_cnt5_data, slgReg.reg_cnt5_data);
  Serial.printf("%3d(0x%02X) : [BDH(0) 1512:1512(1)] cnt5_output_pol_selection\n", slgReg.cnt5_output_pol_selection, slgReg.cnt5_output_pol_selection);
  Serial.printf("%3d(0x%02X) : [BDH(2) 1514:1514(1)] cnt5_cnt_mode_sync_selection\n", slgReg.cnt5_cnt_mode_sync_selection, slgReg.cnt5_cnt_mode_sync_selection);
  Serial.printf("%3d(0x%02X) : [BDH(3) 1515:1515(1)] cnt5_dly_edet_function_selection\n", slgReg.cnt5_dly_edet_function_selection, slgReg.cnt5_dly_edet_function_selection);
  Serial.printf("%3d(0x%02X) : [BEH(0) 1527:1520(8)] lut3_12_dff15_setting\n", slgReg.lut3_12_dff15_setting, slgReg.lut3_12_dff15_setting);
  Serial.printf("%3d(0x%02X) : [BFH(0) 1531:1528(4)] dly_cnt6_clock_source_select\n", slgReg.dly_cnt6_clock_source_select, slgReg.dly_cnt6_clock_source_select);
  Serial.printf("%3d(0x%02X) : [BFH(4) 1535:1532(4)] cnt6_function_and_edge_mode_selection\n", slgReg.cnt6_function_and_edge_mode_selection, slgReg.cnt6_function_and_edge_mode_selection);
  Serial.printf("%3d(0x%02X) : [C0H(0) 1537:1536(2)] cnt6_initial_value_selection\n", slgReg.cnt6_initial_value_selection, slgReg.cnt6_initial_value_selection);
  Serial.printf("%3d(0x%02X) : [C0H(3) 1539:1539(1)] cnt6_output_pol_selection\n", slgReg.cnt6_output_pol_selection, slgReg.cnt6_output_pol_selection);
  Serial.printf("%3d(0x%02X) : [C0H(5) 1541:1541(1)] cnt6_cnt_mode_sync_selection\n", slgReg.cnt6_cnt_mode_sync_selection, slgReg.cnt6_cnt_mode_sync_selection);
  Serial.printf("%3d(0x%02X) : [C0H(6) 1542:1542(1)] cnt6_dly_edet_function_selection\n", slgReg.cnt6_dly_edet_function_selection, slgReg.cnt6_dly_edet_function_selection);
  Serial.printf("%3d(0x%02X) : [C1H(0) 1551:1544(8)] reg_cnt6_data\n", slgReg.reg_cnt6_data, slgReg.reg_cnt6_data);
  Serial.printf("%3d(0x%02X) : [C2H(5) 1557:1557(1)] cnt7_output_pol_selection\n", slgReg.cnt7_output_pol_selection, slgReg.cnt7_output_pol_selection);
  Serial.printf("%3d(0x%02X) : [C2H(7) 1559:1559(1)] cnt7_cnt_mode_sync_selection\n", slgReg.cnt7_cnt_mode_sync_selection, slgReg.cnt7_cnt_mode_sync_selection);
  Serial.printf("%3d(0x%02X) : [C3H(0) 1567:1560(8)] lut3_13_dff16_setting\n", slgReg.lut3_13_dff16_setting, slgReg.lut3_13_dff16_setting);
  Serial.printf("%3d(0x%02X) : [C4H(0) 1571:1568(4)] dly_cnt7_clock_source_select\n", slgReg.dly_cnt7_clock_source_select, slgReg.dly_cnt7_clock_source_select);
  Serial.printf("%3d(0x%02X) : [C4H(4) 1575:1572(4)] cnt7_function_and_edge_mode_selection\n", slgReg.cnt7_function_and_edge_mode_selection, slgReg.cnt7_function_and_edge_mode_selection);
  Serial.printf("%3d(0x%02X) : [C5H(0) 1577:1576(2)] cnt7_initial_value_selection\n", slgReg.cnt7_initial_value_selection, slgReg.cnt7_initial_value_selection);
  Serial.printf("%3d(0x%02X) : [C5H(2) 1578:1578(1)] cnt7_dly_edet_function_selection\n", slgReg.cnt7_dly_edet_function_selection, slgReg.cnt7_dly_edet_function_selection);
  Serial.printf("%3d(0x%02X) : [C6H(0) 1591:1584(8)] reg_cnt7_data\n", slgReg.reg_cnt7_data, slgReg.reg_cnt7_data);
  Serial.printf("%3d(0x%02X) : [C7H(0) 1592:1592(1)] io0_i2c_output_expander_data\n", slgReg.io0_i2c_output_expander_data, slgReg.io0_i2c_output_expander_data);
  Serial.printf("%3d(0x%02X) : [C7H(1) 1593:1593(1)] io0_i2c_output_expander_select\n", slgReg.io0_i2c_output_expander_select, slgReg.io0_i2c_output_expander_select);
  Serial.printf("%3d(0x%02X) : [C7H(2) 1594:1594(1)] io5_i2c_output_expander_data\n", slgReg.io5_i2c_output_expander_data, slgReg.io5_i2c_output_expander_data);
  Serial.printf("%3d(0x%02X) : [C7H(3) 1595:1595(1)] io5_i2c_output_expander_select\n", slgReg.io5_i2c_output_expander_select, slgReg.io5_i2c_output_expander_select);
  Serial.printf("%3d(0x%02X) : [C7H(4) 1596:1596(1)] io6_i2c_output_expander_data\n", slgReg.io6_i2c_output_expander_data, slgReg.io6_i2c_output_expander_data);
  Serial.printf("%3d(0x%02X) : [C7H(5) 1597:1597(1)] io6_i2c_output_expander_select\n", slgReg.io6_i2c_output_expander_select, slgReg.io6_i2c_output_expander_select);
  Serial.printf("%3d(0x%02X) : [C7H(6) 1598:1598(1)] io9_i2c_output_expander_data\n", slgReg.io9_i2c_output_expander_data, slgReg.io9_i2c_output_expander_data);
  Serial.printf("%3d(0x%02X) : [C7H(7) 1599:1599(1)] io9_i2c_output_expander_select\n", slgReg.io9_i2c_output_expander_select, slgReg.io9_i2c_output_expander_select);
  Serial.printf("%3d(0x%02X) : [C8H(1) 1601:1601(1)] i2c_reset_bit_with_reloading_nvm_into_data_register_soft_reset\n", slgReg.i2c_reset_bit_with_reloading_nvm_into_data_register_soft_reset, slgReg.i2c_reset_bit_with_reloading_nvm_into_data_register_soft_reset);
  Serial.printf("%3d(0x%02X) : [C8H(2) 1602:1602(1)] io_latching_enable_during_i2c_write_interface\n", slgReg.io_latching_enable_during_i2c_write_interface, slgReg.io_latching_enable_during_i2c_write_interface);
  Serial.printf("%3d(0x%02X) : [C9H(0) 1615:1608(8)] i2c_write_mask_bits\n", slgReg.i2c_write_mask_bits, slgReg.i2c_write_mask_bits);
  Serial.printf("%3d(0x%02X) : [CAH(0) 1619:1616(4)] i2c_slave_address\n", slgReg.i2c_slave_address, slgReg.i2c_slave_address);
  Serial.printf("%3d(0x%02X) : [CAH(4) 1620:1620(1)] slave_address_selection_a4\n", slgReg.slave_address_selection_a4, slgReg.slave_address_selection_a4);
  Serial.printf("%3d(0x%02X) : [CAH(5) 1621:1621(1)] slave_address_selection_a5\n", slgReg.slave_address_selection_a5, slgReg.slave_address_selection_a5);
  Serial.printf("%3d(0x%02X) : [CAH(6) 1622:1622(1)] slave_address_selection_a6\n", slgReg.slave_address_selection_a6, slgReg.slave_address_selection_a6);
  Serial.printf("%3d(0x%02X) : [CAH(7) 1623:1623(1)] slave_address_selection_a7\n", slgReg.slave_address_selection_a7, slgReg.slave_address_selection_a7);
  Serial.printf("%3d(0x%02X) : [CBH(0) 1631:1624(8)] pattern_id_byte_0\n", slgReg.pattern_id_byte_0, slgReg.pattern_id_byte_0);
  Serial.printf("%3d(0x%02X) : [E0H(0) 1793:1792(2)] register_read_selection_bits\n", slgReg.register_read_selection_bits, slgReg.register_read_selection_bits);
  Serial.printf("%3d(0x%02X) : [E0H(2) 1795:1794(2)] register_write_selection_bits\n", slgReg.register_write_selection_bits, slgReg.register_write_selection_bits);
  Serial.printf("%3d(0x%02X) : [E1H(0) 1801:1800(2)] nvm_configuration_selection_bits\n", slgReg.nvm_configuration_selection_bits, slgReg.nvm_configuration_selection_bits);
  Serial.printf("%3d(0x%02X) : [E2H(2) 1810:1810(1)] write_protect_register_enable\n", slgReg.write_protect_register_enable, slgReg.write_protect_register_enable);
  Serial.printf("%3d(0x%02X) : [E3H(0) 1820:1816(5)] page_selection_for_erase_erseb\n", slgReg.page_selection_for_erase_erseb, slgReg.page_selection_for_erase_erseb);
  Serial.printf("%3d(0x%02X) : [E3H(7) 1823:1823(1)] erase_enable\n", slgReg.erase_enable, slgReg.erase_enable);
  Serial.printf("%3d(0x%02X) : [E4H(0) 1824:1824(1)] protection_lock_bit_prl\n", slgReg.protection_lock_bit_prl, slgReg.protection_lock_bit_prl);

  Serial.println();
}

#endif
