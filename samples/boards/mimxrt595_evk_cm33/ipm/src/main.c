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
#include <stdio.h>

//static const char ping_data[16] = "ping";
volatile int called = 0;

static void ipm_receive_callback(const struct device *ipmdev, void *user_data,
			       uint32_t id, volatile void *data)
{
	printk("get %s", (char *)data);
	if (memcmp((const void *)data, "pong", 4)== 0)
	{
		printk("receive pong message correctly!!!\r\n");
	}
	called = 1;
}

int main(void)
{
	const struct device *ipm_dev;

	ipm_dev = device_get_binding("mail_box");
	if (!ipm_dev) {
		printk("Failed to get IPM device.\n\r");
		return 0;
	}

	ipm_register_callback(ipm_dev, ipm_receive_callback, NULL);

	ipm_set_enabled(ipm_dev, 1);

	printk("start ipm wating for pong message\r\n");
	while (1) {
//		ipm_send(ipm_dev, 1, 0, &ping_data, sizeof(ping_data));
		while(!called)
		{
			k_sleep(K_MSEC(50));
		}
		called = 0;
	}
	return 0;
}
