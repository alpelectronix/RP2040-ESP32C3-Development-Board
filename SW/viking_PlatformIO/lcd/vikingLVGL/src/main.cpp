#include <Arduino.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pico/binary_info.h"
#include "vikingLcdDriver.h"
#include <lvgl.h>
#include "Timer.h"

#define BUFFER_SIZE (WIDTH * HEIGHT)

void customBacklightCallbackFunction()
{
  pwm_clear_irq(pwm_gpio_to_slice_num(BACKLIGHT));
  // Optional Callback Function
}

void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
  int32_t x, y;
  lcdSetCursor(0, 0);            // Set Cursor to (0,0) pixel
  sendLcdCommand(0x2c, NULL, 0); // RAMWR (2Ch): Memory Write
  setLcdMode(DATA_MODE);

  for (y = area->y1; y <= area->y2; y++)
  {
    for (x = area->x1; x <= area->x2; x++)
    {
      lv_color16_t c16;
      c16.full = lv_color_to16(*color_p);
      sendLcdData(c16.full >> 8);
      sendLcdData(c16.full);
      color_p++;
    }
  }

  lv_disp_flush_ready(disp_drv);
}

void repeating_timer_callback()
{
  lv_tick_inc(5);
}

void lv_example_chart_1(void)
{
  lv_obj_t *chart = lv_chart_create(lv_scr_act());
  lv_obj_set_size(chart, 240, 120);
  lv_obj_center(chart);
  lv_chart_set_type(chart, LV_CHART_TYPE_LINE); /*Show lines and points too*/
  lv_chart_set_div_line_count(chart, 10, 20);

  /*Add two data series*/
  lv_chart_series_t *ser1 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
  lv_chart_series_t *ser2 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_SECONDARY_Y);

  /*Set the next points on 'ser1'*/
  lv_chart_set_next_value(chart, ser1, 10);
  lv_chart_set_next_value(chart, ser1, 10);
  lv_chart_set_next_value(chart, ser1, 10);
  lv_chart_set_next_value(chart, ser1, 10);
  lv_chart_set_next_value(chart, ser1, 10);
  lv_chart_set_next_value(chart, ser1, 10);
  lv_chart_set_next_value(chart, ser1, 10);
  lv_chart_set_next_value(chart, ser1, 30);
  lv_chart_set_next_value(chart, ser1, 70);
  lv_chart_set_next_value(chart, ser1, 90);

  /*Directly set points on 'ser2'*/
  ser2->y_points[0] = 90;
  ser2->y_points[1] = 70;
  ser2->y_points[2] = 65;
  ser2->y_points[3] = 65;
  ser2->y_points[4] = 65;
  ser2->y_points[5] = 65;
  ser2->y_points[6] = 65;
  ser2->y_points[7] = 65;
  ser2->y_points[8] = 65;
  ser2->y_points[9] = 65;

  lv_chart_refresh(chart); /*Required after direct set*/
}

void setup()
{
  sleep_ms(1000);
  lcdInit();
  backLightInit(customBacklightCallbackFunction);
  setBackLightPower(80);

  lv_init();

  static lv_disp_draw_buf_t disp_buf;
  static lv_color_t buf_1[BUFFER_SIZE];
  lv_disp_draw_buf_init(&disp_buf, buf_1, NULL, BUFFER_SIZE);

  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &disp_buf;
  disp_drv.hor_res = WIDTH;
  disp_drv.ver_res = HEIGHT;
  lv_disp_drv_register(&disp_drv);

  lv_obj_t *label = lv_label_create(lv_scr_act());
  lv_label_set_text(label, "Alp Electronix");
  lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 5);

  lv_example_chart_1();

  lv_obj_t *label2 = lv_label_create(lv_scr_act());
  lv_label_set_text(label2, "now supports LVGL !");
  lv_obj_align(label2, LV_ALIGN_BOTTOM_MID, 0, -5);


  Timer.repeat(repeating_timer_callback, 1);
}

void loop()
{
  lv_task_handler();
}
