/*
 * Copyright 2022, NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/ipm.h>
#include <zephyr/device.h>
#include <zephyr/init.h>


static const char pong_data[16] = "pong";

//volatile int called = 0;

//static void ipm_receive_callback(const struct device *ipmdev, void *user_data,
//			       uint32_t id, volatile void *data)
//{
//	called = 1;
//}

int main(void)
{
	const struct device *ipm_dev;

	ipm_dev = device_get_binding("mail_box");
	if (!ipm_dev) {
		return -1;
	}

	//ipm_register_callback(ipm_dev, ipm_receive_callback, NULL);
	//ipm_set_enabled(ipm_dev, 1);

	ipm_send(ipm_dev, 1, 0, &pong_data, sizeof(pong_data));
	while (1) {
		k_sleep(K_MSEC(50));
//		ipm_send(ipm_dev, 1, 0, &pong_data, sizeof(pong_data));
	}
	return 0;
}
