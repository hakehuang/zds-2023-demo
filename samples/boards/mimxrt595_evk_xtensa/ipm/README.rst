.. _mimxrt595_evk-imp-sample:

RT595 IMP demo
#####################

Overview
********

This sample can be used for IMP and as an example of
soft off on NXP i.MX RT platforms. The functional behavior is:

* IMP operations

Requirements
************

This application uses MIMXRT595-EVK for the demo.

Building, Flashing and Running
******************************

.. zephyr-app-commands::
   :zephyr-app: samples/boards/mimxrt595_evk_cm33/system_off
   :board: mimxrt595_evk_cm33
   :goals: build flash
   :compact:

Running:

1. Open UART terminal.
2. send message to IMP and echo back received message

Sample Output
=================
MIMXRT595-EVK core output
--------------------------

.. code-block:: console


