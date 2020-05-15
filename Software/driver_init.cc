/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>

struct camera_async_descriptor CAMERA_0;

void CAMERA_0_PORT_init(void)
{
}

void CAMERA_0_CLOCK_init(void)
{
	hri_mclk_set_APBDMASK_PCC_bit(MCLK);
}

void CAMERA_0_init(void)
{
	CAMERA_0_CLOCK_init();
	camera_async_init(&CAMERA_0, PCC);
	CAMERA_0_PORT_init();
}

void system_init(void)
{
	init_mcu();

	CAMERA_0_init();
}
