# How to run

## here we using cgdb as gdb font end, but gdb works well

## start dbus daemon

`
python3 ./dbus_mu_service.py &
`

## start rt595 cm33 core

recommand to start in a screen client

### start rt595 cm33 qemu machine

```
> screen -S qemu_cm33
after enter screen clent run
> cgdb -d gdb-multiarch -x ./gdb_qemu ./qemu-system-arm

or simply

> ./qemu-system-arm -nographic -machine rt595-m33,boot-base-addr=0x18001000 -global rt-lpadc.dma_hw_trigger_nr=24 -kernel ./zephyr_rt595_cm33_ipm.elf -s -S

```

or start in nondebug mode

```
> screen -S qemu_cm33

after enter screen clent run

> ./qemu-system-arm -nographic -machine rt595-m33,boot-base-addr=0x18001000 -global rt-lpadc.dma_hw_trigger_nr=24 -kernel ./zephyr_rt595_cm33_ipm.elf
```

### connect with gdb if you want debug cm33 application

```
cgdb -d gdb-multiarch -x ./gdb_cm33 ./zephyr_rt595_cm33_ipm.elf
```


## start rt595 xtensa core

### start command line

```
> ./qemu-system-xtensa -nographic -machine xt-rt595-nommu  -semihosting  -cpu sample_controller -kernel zephyr_rt595_xtensa_ipm.elf
```

### debug

if you want to start with debug mode call assume your zephyr-sdk installed in `~/zephyr-sdk`

### start the xtensa qemu
```
 ./qemu-system-xtensa -nographic -machine xt-rt595-nommu  -semihosting  -cpu sample_controller -kernel ./zephyr_rt595_xtensa_ipm.elf -s -S
```

or

```
> cgdb -d gdb-multiarch -x ./gdb_xtensa_machine ./qemu-system-xtensa
```


### gdb connection

```
~/zephyr-sdk/xtensa-sample_controller_zephyr-elf/bin/xtensa-sample_controller_zephyr-elf-gdb -x gdb_xtensa  zephyr_rt595_xtensa_ipm.elf
```

## Note:

> 1. screen can be set to background by pressing `Ctrl+A` then `D`, and reattach with `screen -r <clinet id>`. client id can be retriieved by `screen -ls`

> 2. remember to change the gdb port number when you debug both cm33 and xtensa e.g. replace `-s` as `-gdb tcp::1235`


