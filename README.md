# ESP32_sleep_issue

<h2> IDF version</h2>
5.0.3
<h2>How did you build your project?</h2>
VS Code IDE
<h2>device</h2>
esp32s3
<h2>What is the expected behavior?</h2>

When the `sleep_mode_task` task is suspended,
the `esp_light_sleep_start` method is executed.
Every two seconds, it will wake up 
due to the `esp_sleep_enable_timer_wakeup` method. 
After waking up, it will enter "light sleep" again.
This cycle will continue repeatedly.

<h2>What is the actual behavior</h2>

During the execution of this cycle, 
there is a chance of an automatic system restart due to 
the `TG1WDT_SYS_RST` error. 
When I comment out the line `xTaskCreate(lvgl_task,"lvgl_task",8 * 2048, NULL,3,&lvgl_handle);`,
the issue does not occur. How can I resolve this problem?

<h2>Debug Logs</h2>

```c
Hello world!
I (1429) gpio: GPIO[2]| InputEn: 1| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:3 
I (1429) gpio: GPIO[45]| InputEn: 1| OutputEn: 1| OpenDrain: 0| Pullup: 0| Pulldown: 0| Intr:0      
Enabling EXT0 wakeup on pin GPIO2
Enabling timer wakeup on 60S
W (1429) sleep: option 0
D (1489) lcd_panel.rgb: installed pm lock and hold the lock during the whole panel lifecycle
V (1489) intr_alloc: esp_intr_alloc_intrstatus (cpu 1): checking args
V (1489) intr_alloc: esp_intr_alloc_intrstatus (cpu 1): Args okay. Resulting flags 0x90E
D (1499) intr_alloc: Connected src 24 to int 4 (cpu 1)
D (1509) gdma: new group (0) at 0x3c1f7944
D (1509) gdma: new pair (0,0) at 0x3c1f7988
D (1509) gdma: new tx channel (0,0) at 0x3c13c104
D (1519) gdma: tx channel (0,0), (4:64) bytes aligned, burst enabled
V (1519) intr_alloc: esp_intr_alloc_intrstatus (cpu 1): checking args
V (1529) intr_alloc: esp_intr_alloc_intrstatus (cpu 1): Args okay. Resulting flags 0x80E
D (1539) intr_alloc: Connected src 71 to int 9 (cpu 1)
D (1539) gdma: install interrupt service for tx channel (0,0)
D (1549) lcd_panel.rgb: new rgb panel(0) @0x3fcac860, num_fbs=2, fb_size=768000, bb0 @0x3fcaca88, bb1 @0x3fcbc964, bb_size=25600
D (1559) lcd_panel.rgb: fb[0] @0x3c080900
D (1569) lcd_panel.rgb: fb[1] @0x3c13c140
D (1569) lcd_hal: n=6,a=3,b=2,mo=1
D (1579) lcd_panel.rgb: rgb panel(0) start, pclk=24000000Hz
I (1579) gpio: GPIO[38]| InputEn: 1| OutputEn: 1| OpenDrain: 0| Pullup: 0| Pulldown: 0| Intr:0 
I (1589) GT911: Checking for GT911 Touch Controller
V (1589) intr_alloc: esp_intr_alloc_intrstatus (cpu 1): checking args
V (1599) intr_alloc: esp_intr_alloc_intrstatus (cpu 1): Args okay. Resulting flags 0xE
D (1609) intr_alloc: Connected src 42 to int 12 (cpu 1)
I (1619) GT911:         Product ID: 911
I (1619) GT911:         Vendor ID: 0x00
I (1619) GT911:         X Resolution: 800
I (1629) GT911:         Y Resolution: 480
I (1629) GT911:          GT911 Touch init success
I (1629) lvgl task: task suspend 
I (1629) lvgl task: task suspend 
W (2449) sleep: go to sleep mode
D (2549) sleep: RTC_PERIPH: ON
W (2549) sleep: Wake up from timer
W (2549) sleep: go to sleep mode
D (2649) sleep: RTC_PERIPH: ON
W (2649) sleep: Wake up from timer
W (2649) sleep: go to sleep mode
D (2749) sleep: RTC_PERIPH: ON
W (2749) sleep: Wake up from timer
W (2749) sleep: go to sleep mode
D (2849) sleep: RTC_PERIPH: ON
W (2849) sleep: Wake up from timer
W (2849) sleep: go to sleep mode
D (2949) sleep: RTC_PERIPH: ON
W (2949) sleep: Wake up from timer
W (2949) sleep: go to sleep mode
D (3049) sleep: RTC_PERIPH: ON
W (3049) sleep: Wake up from timer
W (3049) sleep: go to sleep mode
D (3149) sleep: RTC_PERIPH: ON
W (3149) sleep: Wake up from timer
W (3149) sleep: go to sleep mode
D (3249) sleep: RTC_PERIPH: ON
W (3249) sleep: Wake up from timer
W (3249) sleep: go to sleep mode
D (3349) sleep: RTC_PERIPH: ON
W (3349) sleep: Wake up from timer
W (3349) sleep: go to sleep mode
D (3449) sleep: RTC_PERIPH: ON
W (3449) sleep: Wake up from timer
W (3449) sleep: go to sleep mode
D (3549) sleep: RTC_PERIPH: ON
W (3549) sleep: Wake up from timer
W (3549) sleep: go to sleep mode
D (3649) sleep: RTC_PERIPH: ON
W (3649) sleep: Wake up from timer
W (3649) sleep: go to sleep mode
D (3749) sleep: RTC_PERIPH: ON
W (3749) sleep: Wake up from timer
W (3749) sleep: go to sleep mode
D (3849) sleep: RTC_PERIPH: ON
W (3849) sleep: Wake up from timer
W (3849) sleep: go to sleep mode
D (3949) sleep: RTC_PERIPH: ON
W (3949) sleep: Wake up from timer
W (3949) sleep: go to sleep mode
D (4049) sleep: RTC_PERIPH: ON
W (4049) sleep: Wake up from timer
W (4049) sleep: go to sleep mode
D (4149) sleep: RTC_PERIPH: ON
W (4149) sleep: Wake up from timer
W (4149) sleep: go to sleep mode
D (4249) sleep: RTC_PERIPH: ON
W (4249) sleep: Wake up from timer
W (4249) sleep: go to sleep mode
D (4349) sleep: RTC_PERIPH: ON
W (4349) sleep: Wake up from timer
W (4349) sleep: go to sleep mode
D (4449) sleep: RTC_PERIPH: ON
W (4449) sleep: Wake up from timer
W (4449) sleep: go to sleep mode
D (4549) sleep: RTC_PERIPH: ON
W (4549) sleep: Wake up from timer
W (4549) sleep: go to sleep mode
D ESP-ROM:esp32s3-20210327
Build:Mar 27 2021
rst:0x8 (TG1WDT_SYS_RST),boot:0xb (SPI_FAST_FLASH_BOOT)
Saved PC:0x4037df42
0x4037df42: _xt_panic at C:/Espressif/frameworks/esp-idf-v5.0.3/components/esp_system/port/arch/xtensa/panic_handler_asm.S:61

SPIWP:0xee
mode:DIO, clock div:1
load:0x3fce3810,len:0x468
load:0x403c9700,len:0xad4
load:0x403cc700,len:0x2808
entry 0x403c9880
I (118) cpu_start: Multicore app
I (118) octal_psram: vendor id    : 0x0d (AP)
I (118) octal_psram: dev id       : 0x02 (generation 3)
I (121) octal_psram: density      : 0x03 (64 Mbit)
I (127) octal_psram: good-die     : 0x01 (Pass)
I (132) octal_psram: Latency      : 0x01 (Fixed)
I (137) octal_psram: VCC          : 0x01 (3V)
I (142) octal_psram: SRF          : 0x01 (Fast Refresh)
I (148) octal_psram: BurstType    : 0x01 (Hybrid Wrap)
I (154) octal_psram: BurstLen     : 0x01 (32 Byte)
I (159) octal_psram: Readlatency  : 0x02 (10 cycles@Fixed)
I (166) octal_psram: DriveStrength: 0x00 (1/1)
D (171) MSPI Timing: tuning success, best point is index 4
I (176) MSPI Timing: PSRAM timing tuning index: 4
I (182) esp_psram: Found 8MB PSRAM device
I (186) esp_psram: Speed: 80MHz
V mmu_psram: Instructions from flash page3 copy to SPIRAM page0, Offset: 3
V (230) mmu_psram: after copy instruction, page_id is 6
I (230) mmu_psram: Instructions copied and mapped to SPIRAM
V (230) esp_psram: after copy .text, used page is 6, start_page is 6, psram_available_size is 7995392 B
V mmu_psram: Rodata from flash page1 copy to SPIRAM page6, Offset: -5
V (255) mmu_psram: after copy rodata, page_id is 8
I (255) mmu_psram: Read only data copied and mapped to SPIRAM
V (257) esp_psram: after copy .rodata, used page is 2, start_page is 8, psram_available_size is 7864320 B
V (266) mmu: after coalescing, 1 regions are left
V (271) mmu: found laddr is 0x80000
V (275) esp_psram: 8bit-aligned-region: actual_mapped_len is 0x780000 bytes
V (282) esp_psram: 8bit-aligned-range: 0x780000 B, starting from: 0x3c080000
I (289) cpu_start: Pro cpu up.
I (293) cpu_start: Starting app cpu, entry point is 0x403797a0
0x403797a0: call_start_cpu1 at C:/Espressif/frameworks/esp-idf-v5.0.3/components/esp_system/port/cpu_start.c:143

I (0) cpu_start: App cpu up.
V CACHE_ERR: illegal error intr clr & ena mask is: 0x3f
V CACHE_ERR: core 1 access error intr clr & ena mask is: 0x1f
I (717) esp_psram: SPI SRAM memory test OK
D (717) efuse: In EFUSE_BLK1__DATA4_REG is used 7 bits starting with 20 bit
D (717) efuse: In EFUSE_BLK1__DATA5_REG is used 8 bits starting with 3 bit
D (724) efuse: In EFUSE_BLK1__DATA5_REG is used 5 bits starting with 11 bit
D (731) efuse: In EFUSE_BLK1__DATA4_REG is used 7 bits starting with 13 bit
D (738) efuse: In EFUSE_BLK1__DATA4_REG is used 7 bits starting with 20 bit
D (745) efuse: In EFUSE_BLK1__DATA4_REG is used 5 bits starting with 27 bit
D (753) efuse: In EFUSE_BLK1__DATA5_REG is used 3 bits starting with 0 bit
D (759) efuse: In EFUSE_BLK1__DATA5_REG is used 8 bits starting with 3 bit
D (766) efuse: In EFUSE_BLK1__DATA4_REG is used 7 bits starting with 13 bit
D (773) efuse: In EFUSE_BLK1__DATA4_REG is used 7 bits starting with 20 bit
D (780) efuse: In EFUSE_BLK1__DATA4_REG is used 5 bits starting with 27 bit
D (787) efuse: In EFUSE_BLK1__DATA5_REG is used 3 bits starting with 0 bit
D (794) efuse: In EFUSE_BLK1__DATA5_REG is used 8 bits starting with 3 bit
D (809) clk: RTC_SLOW_CLK calibration value: 3866611
V CACHE_ERR: illegal error intr clr & ena mask is: 0x3f
V CACHE_ERR: core 0 access error intr clr & ena mask is: 0x1f
I (818) cpu_start: Pro cpu start user code
I (822) cpu_start: cpu freq: 240000000 Hz
I (826) cpu_start: Application information:
I (831) cpu_start: Project name:     hello_world
I (837) cpu_start: App version:      1
I (841) cpu_start: Compile time:     Nov 16 2023 11:21:18
I (847) cpu_start: ELF file SHA256:  a9eb6350022a4ac6...
I (853) cpu_start: ESP-IDF:          v5.0.3-dirty
I (858) cpu_start: Min chip rev:     v0.0
I (863) cpu_start: Max chip rev:     v0.99 
I (868) cpu_start: Chip rev:         v0.2
V (873) memory_layout: reserved range is 0x3c072b9c - 0x3c072bbc
D (879) memory_layout: Checking 5 reserved memory ranges:
D (884) memory_layout: Reserved memory range 0x3c000000 - 0x3e000000
D (891) memory_layout: Reserved memory range 0x3fc88000 - 0x3fc9b200
D (897) memory_layout: Reserved memory range 0x3fc9b200 - 0x3fca7718
D (903) memory_layout: Reserved memory range 0x3fceee34 - 0x3fcf0000
D (910) memory_layout: Reserved memory range 0x600fe000 - 0x600fe034
D (916) memory_layout: Building list of available memory regions:
V (922) memory_layout: Examining memory region 0x3c000000 - 0x3e000000
V (929) memory_layout: Region 0x3c000000 - 0x3e000000 inside of reserved 0x3c000000 - 0x3e000000    
V (938) memory_layout: Examining memory region 0x3fc88000 - 0x3fc90000
V (945) memory_layout: Region 0x3fc88000 - 0x3fc90000 inside of reserved 0x3fc88000 - 0x3fc9b200    
V (953) memory_layout: Examining memory region 0x3fc90000 - 0x3fca0000
V (960) memory_layout: Start of region 0x3fc90000 - 0x3fca0000 overlaps reserved 0x3fc88000 - 0x3fc9b200
V (970) memory_layout: Region 0x3fc9b200 - 0x3fca0000 inside of reserved 0x3fc9b200 - 0x3fca7718    
V (978) memory_layout: Examining memory region 0x3fca0000 - 0x3fcb0000
V (985) memory_layout: Start of region 0x3fca0000 - 0x3fcb0000 overlaps reserved 0x3fc9b200 - 0x3fca7718
D (995) memory_layout: Available memory region 0x3fca7718 - 0x3fcb0000
V (1001) memory_layout: Examining memory region 0x3fcb0000 - 0x3fcc0000
D (1008) memory_layout: Available memory region 0x3fcb0000 - 0x3fcc0000
V (1014) memory_layout: Examining memory region 0x3fcc0000 - 0x3fcd0000
D (1021) memory_layout: Available memory region 0x3fcc0000 - 0x3fcd0000
V (1028) memory_layout: Examining memory region 0x3fcd0000 - 0x3fce0000
D (1035) memory_layout: Available memory region 0x3fcd0000 - 0x3fce0000
V (1041) memory_layout: Examining memory region 0x3fce0000 - 0x3fce9710
D (1048) memory_layout: Available memory region 0x3fce0000 - 0x3fce9710
V (1055) memory_layout: Examining memory region 0x3fce9710 - 0x3fcf0000
V (1061) memory_layout: End of region 0x3fce9710 - 0x3fcf0000 overlaps reserved 0x3fceee34 - 0x3fcf0000
D (1071) memory_layout: Available memory region 0x3fce9710 - 0x3fceee34
V (1077) memory_layout: Examining memory region 0x600fe000 - 0x60100000
V (1084) memory_layout: Start of region 0x600fe000 - 0x60100000 overlaps reserved 0x600fe000 - 0x600fe034
D (1094) memory_layout: Available memory region 0x600fe034 - 0x60100000
I (1100) heap_init: Initializing. RAM available for dynamic allocation:
D (1108) heap_init: New heap initialised at 0x3fca7718
I (1113) heap_init: At 3FCA7718 len 00041FF8 (263 KiB): DRAM
I (1119) heap_init: At 3FCE9710 len 00005724 (21 KiB): STACK/DRAM
D (1126) heap_init: New heap initialised at 0x600fe034
I (1131) heap_init: At 600FE034 len 00001FCC (7 KiB): RTCRAM
I (1138) esp_psram: Adding pool of 7680K of PSRAM memory to heap allocator
V (1145) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): checking args
V (1152) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): Args okay. Resulting flags 0x40E
D (1160) intr_alloc: Connected src 39 to int 2 (cpu 0)
V (1165) memspi: raw_chip_id: 18405E

V (1169) memspi: chip_id: 5E4018

V (1172) memspi: raw_chip_id: 18405E

V (1176) memspi: chip_id: 5E4018

D (1180) spi_flash: trying chip: issi
D (1183) spi_flash: trying chip: gd
D (1187) spi_flash: trying chip: mxic
D (1191) spi_flash: trying chip: winbond
D (1195) spi_flash: trying chip: boya
D (1198) spi_flash: trying chip: th
D (1202) spi_flash: trying chip: mxic (opi)
D (1206) spi_flash: trying chip: generic
I (1210) spi_flash: detected chip: generic
I (1215) spi_flash: flash io: qio
D (1219) chip_generic: set_io_mode: status before 0x200
V (1224) chip_generic: set_io_mode: status update 0x200
D (1229) cpu_start: calling init function: 0x4203ded0
0x4203ded0: _GLOBAL__sub_I__ZN9__gnu_cxx9__freeresEv at eh_alloc.cc:?

D (1235) cpu_start: calling init function: 0x4203de94
0x4203de94: _GLOBAL__sub_I___cxa_get_globals_fast at eh_globals.cc:?

D (1240) cpu_start: calling init function: 0x42039930
0x42039930: esp_ipc_init at C:/Espressif/frameworks/esp-idf-v5.0.3/components/esp_system/esp_ipc.c:115

D (1245) cpu_start: calling init function: 0x42002cb8
0x42002cb8: esp_reset_reason_init at C:/Espressif/frameworks/esp-idf-v5.0.3/components/esp_system/port/soc/esp32s3/reset_reason.c:67

D (1250) cpu_start: calling init function: 0x42001d94
0x42001d94: esp_init_app_elf_sha256 at C:/Espressif/frameworks/esp-idf-v5.0.3/components/esp_app_format/esp_app_desc.c:69

D (1255) cpu_start: calling init function: 0x42006cec on core: 0
0x42006cec: __esp_system_init_fn_esp_timer_startup_init at C:/Espressif/frameworks/esp-idf-v5.0.3/components/esp_timer/src/esp_timer.c:551

V (1261) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): checking args
V (1268) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): Args okay. Resulting flags 0xC02
D (1276) intr_alloc: Connected src 59 to int 3 (cpu 0)
D (1281) cpu_start: calling init function: 0x4203b668 on core: 0
0x4203b668: __esp_system_init_fn_esp_sleep_startup_init at C:/Espressif/frameworks/esp-idf-v5.0.3/components/esp_hw_support/sleep_modes.c:1516

I (1287) sleep: Configure to isolate all GPIO pins in sleep state
I (1294) sleep: Enable automatic switching of GPIO sleep configuration
D (1301) cpu_start: calling init function: 0x420029b8 on core: 0
0x420029b8: __esp_system_init_fn_init_components0 at C:/Espressif/frameworks/esp-idf-v5.0.3/components/esp_system/startup.c:484

V (1319) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): checking args
V (1319) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): Args okay. Resulting flags 0x40E
D (1322) intr_alloc: Connected src 79 to int 9 (cpu 0)
I (1327) cpu_start: Starting scheduler on PRO CPU.
V (1333) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): checking args
V (1333) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): Args okay. Resulting flags 0x402
D (1333) intr_alloc: Connected src 57 to int 12 (cpu 0)
V (1333) intr_alloc: esp_intr_alloc_intrstatus (cpu 1): checking args
V (1343) intr_alloc: esp_intr_alloc_intrstatus (cpu 1): Args okay. Resulting flags 0x40E
D (1343) intr_alloc: Connected src 80 to int 2 (cpu 1)
I (1353) cpu_start: Starting scheduler on APP CPU.
V (1363) intr_alloc: esp_intr_alloc_intrstatus (cpu 1): checking args
V (1363) intr_alloc: esp_intr_alloc_intrstatus (cpu 1): Args okay. Resulting flags 0x402
D (1373) intr_alloc: Connected src 58 to int 3 (cpu 1)
D (1383) heap_init: New heap initialised at 0x3fce9710
I (1383) esp_psram: Reserving pool of 32K of internal memory for DMA/internal allocations
D (1393) esp_psram: Allocating block of size 32768 bytes
V (1393) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): checking args
V (1403) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): Args okay. Resulting flags 0xE
D (1413) intr_alloc: Connected src 52 to int 13 (cpu 0)
Hello world!
```
