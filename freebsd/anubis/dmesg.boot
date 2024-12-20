---<<BOOT>>---
Copyright (c) 1992-2019 The FreeBSD Project.
Copyright (c) 1979, 1980, 1983, 1986, 1988, 1989, 1991, 1992, 1993, 1994
	The Regents of the University of California. All rights reserved.
FreeBSD is a registered trademark of The FreeBSD Foundation.
FreeBSD 12.1-RELEASE-p3 GENERIC amd64
FreeBSD clang version 8.0.1 (tags/RELEASE_801/final 366581) (based on LLVM 8.0.1)
VT(efifb): resolution 1024x768
CPU: AMD A6-4455M APU with Radeon(tm) HD Graphics    (2096.31-MHz K8-class CPU)
  Origin="AuthenticAMD"  Id=0x610f01  Family=0x15  Model=0x10  Stepping=1
  Features=0x178bfbff<FPU,VME,DE,PSE,TSC,MSR,PAE,MCE,CX8,APIC,SEP,MTRR,PGE,MCA,CMOV,PAT,PSE36,CLFLUSH,MMX,FXSR,SSE,SSE2,HTT>
  Features2=0x3e98320b<SSE3,PCLMULQDQ,MON,SSSE3,FMA,CX16,SSE4.1,SSE4.2,POPCNT,AESNI,XSAVE,OSXSAVE,AVX,F16C>
  AMD Features=0x2e500800<SYSCALL,NX,MMX+,FFXSR,Page1GB,RDTSCP,LM>
  AMD Features2=0x1ebbfff<LAHF,CMP,SVM,ExtAPIC,CR8,ABM,SSE4A,MAS,Prefetch,OSVW,IBS,XOP,SKINIT,WDT,LWP,FMA4,TCE,NodeId,TBM,Topology,PCXC,PNXC>
  Structured Extended Features=0x8<BMI1>
  SVM: NP,NRIP,VClean,AFlush,DAssist,NAsids=65536
  TSC: P-state invariant, performance statistics
real memory  = 8589934592 (8192 MB)
avail memory = 7691628544 (7335 MB)
Event timer "LAPIC" quality 600
ACPI APIC Table: <SECCSD LH43STAR>
FreeBSD/SMP: Multiprocessor System Detected: 2 CPUs
FreeBSD/SMP: 1 package(s) x 2 core(s)
random: unblocking device.
Firmware Warning (ACPI): Optional FADT field Pm2ControlBlock has valid Length but zero Address: 0x0000000000000000/0x1 (20181213/tbfadt-796)
ioapic0 <Version 2.1> irqs 0-23 on motherboard
Launching APs: 1
Timecounter "TSC" frequency 2096307349 Hz quality 1000
Cuse v0.1.36 @ /dev/cuse
random: entropy device external interface
000.000018 [4335] netmap_init               netmap: loaded module
[ath_hal] loaded
module_register_init: MOD_LOAD (vesa, 0xffffffff8112e0f0, 0) error 19
kbd1 at kbdmux0
nexus0
efirtc0: <EFI Realtime Clock> on motherboard
efirtc0: registered as a time-of-day clock, resolution 1.000000s
cryptosoft0: <software crypto> on motherboard
aesni0: <AES-CBC,AES-CCM,AES-GCM,AES-ICM,AES-XTS> on motherboard
acpi0: <SECCSD LH43STAR> on motherboard
acpi0: Power Button (fixed)
cpu0: <ACPI CPU> on acpi0
attimer0: <AT timer> port 0x40-0x43 irq 0 on acpi0
Timecounter "i8254" frequency 1193182 Hz quality 0
Event timer "i8254" frequency 1193182 Hz quality 100
atrtc0: <AT realtime clock> port 0x70-0x71 irq 8 on acpi0
atrtc0: registered as a time-of-day clock, resolution 1.000000s
Event timer "RTC" frequency 32768 Hz quality 0
hpet0: <High Precision Event Timer> iomem 0xfed00000-0xfed003ff on acpi0
Timecounter "HPET" frequency 14318180 Hz quality 950
Timecounter "ACPI-fast" frequency 3579545 Hz quality 900
acpi_timer0: <32-bit timer at 3.579545MHz> port 0x808-0x80b on acpi0
acpi_ec0: <Embedded Controller: GPE 0x3> port 0x62,0x66 on acpi0
pcib0: <ACPI Host-PCI bridge> port 0xcf8-0xcff on acpi0
pci0: <ACPI PCI bus> on pcib0
vgapci0: <VGA-compatible display> port 0xf000-0xf0ff mem 0xc0000000-0xcfffffff,0xfeb00000-0xfeb3ffff at device 1.0 on pci0
vgapci0: Boot video device
hdac0: <ATI (0x9902) HDA Controller> mem 0xfeb44000-0xfeb47fff at device 1.1 on pci0
hdac0: hdac_get_capabilities: Invalid corb size (0)
device_attach: hdac0 attach returned 6
pcib1: <ACPI PCI-PCI bridge> at device 4.0 on pci0
pci1: <ACPI PCI bus> on pcib1
re0: <RealTek 8168/8111 B/C/CP/D/DP/E/F/G PCIe Gigabit Ethernet> port 0xe000-0xe0ff mem 0xd0004000-0xd0004fff,0xd0000000-0xd0003fff at device 0.0 on pci1
re0: Using 1 MSI-X message
re0: turning off MSI enable bit.
re0: ASPM disabled
re0: Chip rev. 0x2c800000
re0: MAC rev. 0x00100000
miibus0: <MII bus> on re0
rgephy0: <RTL8169S/8110S/8211 1000BASE-T media interface> PHY 1 on miibus0
rgephy0:  none, 10baseT, 10baseT-FDX, 10baseT-FDX-flow, 100baseTX, 100baseTX-FDX, 100baseTX-FDX-flow, 1000baseT, 1000baseT-master, 1000baseT-FDX, 1000baseT-FDX-master, 1000baseT-FDX-flow, 1000baseT-FDX-flow-master, auto, auto-flow
re0: Using defaults for TSO: 65518/35/2048
re0: Ethernet address: 50:b7:c3:78:97:4d
re0: netmap queues/slots: TX 1/256, RX 1/256
xhci0: <XHCI (generic) USB 3.0 controller> mem 0xfeb48000-0xfeb49fff at device 16.0 on pci0
xhci0: 32 bytes context size, 64-bit DMA
xhci0: Unable to map MSI-X table
usbus0 on xhci0
usbus0: 5.0Gbps Super Speed USB v3.0
ahci0: <AMD Hudson-2 AHCI SATA controller> port 0xf140-0xf147,0xf130-0xf133,0xf120-0xf127,0xf110-0xf113,0xf100-0xf10f mem 0xfeb4e000-0xfeb4e7ff at device 17.0 on pci0
ahci0: AHCI v1.30 with 2 6Gbps ports, Port Multiplier supported
ahcich0: <AHCI channel> at channel 0 on ahci0
ahcich3: <AHCI channel> at channel 3 on ahci0
ohci0: <AMD FCH USB Controller> mem 0xfeb4d000-0xfeb4dfff at device 18.0 on pci0
usbus1 on ohci0
usbus1: 12Mbps Full Speed USB v1.0
ehci0: <AMD FCH USB 2.0 controller> mem 0xfeb4c000-0xfeb4c0ff at device 18.2 on pci0
usbus2: EHCI version 1.0
usbus2 on ehci0
usbus2: 480Mbps High Speed USB v2.0
ohci1: <AMD FCH USB Controller> mem 0xfeb4b000-0xfeb4bfff at device 19.0 on pci0
usbus3 on ohci1
usbus3: 12Mbps Full Speed USB v1.0
ehci1: <AMD FCH USB 2.0 controller> mem 0xfeb4a000-0xfeb4a0ff at device 19.2 on pci0
usbus4: EHCI version 1.0
usbus4 on ehci1
usbus4: 480Mbps High Speed USB v2.0
hdac0: <AMD Hudson-2 HDA Controller> mem 0xfeb40000-0xfeb43fff at device 20.2 on pci0
isab0: <PCI-ISA bridge> at device 20.3 on pci0
isa0: <ISA bus> on isab0
pcib2: <ACPI PCI-PCI bridge> at device 20.4 on pci0
pci2: <ACPI PCI bus> on pcib2
pcib3: <ACPI PCI-PCI bridge> at device 21.0 on pci0
pci3: <ACPI PCI bus> on pcib3
ath0: <Atheros AR946x/AR948x> mem 0xfea00000-0xfea7ffff at device 0.0 on pci3
ar9300_flash_map: unimplemented for now
Restoring Cal data from DRAM
Restoring Cal data from EEPROM
Restoring Cal data from Flash
Restoring Cal data from Flash
Restoring Cal data from OTP
ar9300_hw_attach: ar9300_eeprom_attach returned 0
ath0: [HT] enabling HT modes
ath0: [HT] enabling short-GI in 20MHz mode
ath0: [HT] 1 stream STBC receive enabled
ath0: [HT] 1 stream STBC transmit enabled
ath0: [HT] LDPC transmit/receive enabled
ath0: [HT] 2 RX streams; 2 TX streams
ath0: AR9460 mac 640.2 RF5110 phy 3877.8
ath0: 2GHz radio: 0x0000; 5GHz radio: 0x0000
acpi_acad0: <AC Adapter> on acpi0
battery0: <ACPI Control Method Battery> on acpi0
acpi_lid0: <Control Method Lid Switch> on acpi0
acpi_button0: <Power Button> on acpi0
acpi_tz0: <Thermal Zone> port 0x100-0x107 on acpi0
atkbdc0: <Keyboard controller (i8042)> port 0x60,0x64 irq 1 on acpi0
atkbd0: <AT Keyboard> irq 1 on atkbdc0
kbd0 at atkbd0
atkbd0: [GIANT-LOCKED]
psm0: <PS/2 Mouse> irq 12 on atkbdc0
psm0: [GIANT-LOCKED]
psm0: model Generic PS/2 mouse, device ID 0
hwpstate0: <Cool`n'Quiet 2.0> on cpu0
ZFS filesystem version: 5
ZFS storage pool version: features support (5000)
Timecounters tick every 1.000 msec
hdacc0: <Realtek ALC269 HDA CODEC> at cad 0 on hdac0
hdaa0: <Realtek ALC269 Audio Function Group> at nid 1 on hdacc0
pcm0: <Realtek ALC269 (Analog)> at nid 20 and 24 on hdaa0
pcm1: <Realtek ALC269 (Analog)> at nid 21 and 25 on hdaa0
ugen3.1: <AMD OHCI root HUB> at usbus3
ugen4.1: <AMD EHCI root HUB> at usbus4
uhub0: <AMD OHCI root HUB, class 9/0, rev 1.00/1.00, addr 1> on usbus3
uhub1: <AMD EHCI root HUB, class 9/0, rev 2.00/1.00, addr 1> on usbus4
ugen2.1: <AMD EHCI root HUB> at usbus2
uhub2: <AMD EHCI root HUB, class 9/0, rev 2.00/1.00, addr 1> on usbus2
ugen0.1: <0x1022 XHCI root HUB> at usbus0
ugen1.1: <AMD OHCI root HUB> at usbus1
uhub3: <0x1022 XHCI root HUB, class 9/0, rev 3.00/1.00, addr 1> on usbus0
uhub4: <AMD OHCI root HUB, class 9/0, rev 1.00/1.00, addr 1> on usbus1
ada0 at ahcich0 bus 0 scbus0 target 0 lun 0
ada0: <ADATA SP900 5.0.7b> ATA8-ACS SATA 3.x device
ada0: Serial Number 7E0320038352
ada0: 600.000MB/s transfers (SATA 3.x, UDMA6, PIO 8192bytes)
ada0: Command Queueing enabled
ada0: 244198MB (500118192 512 byte sectors)
Trying to mount root from zfs:zroot/ROOT/default []...
GEOM_ELI: Device ada0p4.eli created.
GEOM_ELI: Encryption: AES-XTS 256
GEOM_ELI:     Crypto: hardware
Root mount waiting for: usbus4 usbus3 usbus2 usbus1 usbus0
uhub0: 5 ports with 5 removable, self powered
uhub4: 5 ports with 5 removable, self powered
uhub3: 4 ports with 4 removable, self powered
ugen0.2: <Logitech USB Receiver> at usbus0
ukbd0 on uhub3
ukbd0: <Logitech USB Receiver, class 0/0, rev 2.00/12.03, addr 1> on usbus0
kbd2 at ukbd0
Root mount waiting for: usbus4 usbus2
Root mount waiting for: usbus4 usbus2
uhub2: 5 ports with 5 removable, self powered
uhub1: 5 ports with 5 removable, self powered
Root mount waiting for: usbus4
ugen3.2: <vendor 0x0cf3 product 0x3004> at usbus3
ugen4.2: <Generic WebCam SC-13HDL12131N> at usbus4
[drm] radeon kernel modesetting enabled.
drmn0: <drmn> on vgapci0
vgapci0: child drmn0 requested pci_enable_io
vgapci0: child drmn0 requested pci_enable_io
[drm] initializing kernel modesetting (ARUBA 0x1002:0x990A 0x144D:0xC660 0x00).
[drm:radeon_device_init] Unable to find PCI I/O BAR
[drm:radeon_atombios_init] Unable to find PCI I/O BAR; using MMIO for ATOM IIO
ATOM BIOS: BR042452.007
drmn0: VRAM: 512M 0x0000000000000000 - 0x000000001FFFFFFF (512M used)
drmn0: GTT: 1024M 0x0000000020000000 - 0x000000005FFFFFFF
Successfully added WC MTRR for [0xc0000000-0xcfffffff]: 0;
[drm] Detected VRAM RAM=512M, BAR=256M
[drm] RAM width 64bits DDR
[TTM] Zone  kernel: Available graphics memory: 3888642 kiB
[TTM] Zone   dma32: Available graphics memory: 2097152 kiB
[TTM] Initializing pool allocator
[drm] radeon: 512M of VRAM memory ready
[drm] radeon: 1024M of GTT memory ready.
[drm] Loading ARUBA Microcode
drmn0: successfully loaded firmware image with name: radeon/ARUBA_pfp.bin
drmn0: successfully loaded firmware image with name: radeon/ARUBA_me.bin
drmn0: successfully loaded firmware image with name: radeon/ARUBA_rlc.bin
[drm] Internal thermal controller without fan control
[drm] radeon: dpm initialized
drmn0: successfully loaded firmware image with name: radeon/TAHITI_uvd.bin
drmn0: successfully loaded firmware image with name: radeon/TAHITI_vce.bin
[drm] Found VCE firmware/feedback version 50.0.1 / 17!
[drm] GART: num cpu pages 262144, num gpu pages 262144
[drm] PCIE GART of 1024M enabled (table at 0x00000000001D6000).
drmn0: WB enabled
drmn0: fence driver on ring 0 use gpu addr 0x0000000020000c00 and cpu addr 0x0xfffff8003ab8ac00
drmn0: fence driver on ring 5 use gpu addr 0x0000000000075a18 and cpu addr 0x0xfffff800c0075a18
drmn0: fence driver on ring 6 use gpu addr 0x0000000020000c18 and cpu addr 0x0xfffff8003ab8ac18
drmn0: fence driver on ring 7 use gpu addr 0x0000000020000c1c and cpu addr 0x0xfffff8003ab8ac1c
drmn0: fence driver on ring 1 use gpu addr 0x0000000020000c04 and cpu addr 0x0xfffff8003ab8ac04
drmn0: fence driver on ring 2 use gpu addr 0x0000000020000c08 and cpu addr 0x0xfffff8003ab8ac08
drmn0: fence driver on ring 3 use gpu addr 0x0000000020000c0c and cpu addr 0x0xfffff8003ab8ac0c
drmn0: fence driver on ring 4 use gpu addr 0x0000000020000c10 and cpu addr 0x0xfffff8003ab8ac10
[drm] Supports vblank timestamp caching Rev 2 (21.10.2013).
[drm] Driver supports precise vblank timestamp query.
drmn0: radeon: MSI limited to 32-bit
drmn0: radeon: using MSI.
[drm] radeon: irq initialized.
[drm] ring test on 0 succeeded in 3 usecs
[drm] ring test on 3 succeeded in 4 usecs
[drm] ring test on 4 succeeded in 3 usecs
[drm:uvd_v1_0_start] UVD not responding, trying to reset the VCPU!!!
[drm:uvd_v1_0_start] UVD not responding, trying to reset the VCPU!!!
[drm:uvd_v1_0_start] UVD not responding, trying to reset the VCPU!!!
[drm:uvd_v1_0_start] UVD not responding, trying to reset the VCPU!!!
[drm:uvd_v1_0_start] UVD not responding, trying to reset the VCPU!!!
[drm:uvd_v1_0_start] UVD not responding, trying to reset the VCPU!!!
[drm:uvd_v1_0_start] UVD not responding, trying to reset the VCPU!!!
[drm:uvd_v1_0_start] UVD not responding, trying to reset the VCPU!!!
[drm:uvd_v1_0_start] UVD not responding, trying to reset the VCPU!!!
[drm:uvd_v1_0_start] UVD not responding, trying to reset the VCPU!!!
[drm:uvd_v1_0_start] UVD not responding, giving up!!!
drmn0: failed initializing UVD (-1).
[drm:vce_v1_0_start] VCE not responding, trying to reset the ECPU!!!
[drm:vce_v1_0_start] VCE not responding, trying to reset the ECPU!!!
[drm:vce_v1_0_start] VCE not responding, trying to reset the ECPU!!!
[drm:vce_v1_0_start] VCE not responding, trying to reset the ECPU!!!
[drm:vce_v1_0_start] VCE not responding, trying to reset the ECPU!!!
[drm:vce_v1_0_start] VCE not responding, trying to reset the ECPU!!!
[drm:vce_v1_0_start] VCE not responding, trying to reset the ECPU!!!
[drm:vce_v1_0_start] VCE not responding, trying to reset the ECPU!!!
[drm:vce_v1_0_start] VCE not responding, trying to reset the ECPU!!!
[drm:vce_v1_0_start] VCE not responding, trying to reset the ECPU!!!
[drm:vce_v1_0_start] VCE not responding, giving up!!!
drmn0: failed initializing VCE (-1).
[drm:r600_ib_test] radeon: fence wait timed out.
[drm:radeon_ib_ring_tests] radeon: failed testing IB on GFX ring (-60).
[drm:radeon_device_init] ib ring test failed (-60).
[drm] Connector HDMI-A-1: get mode from tunables:
[drm]   - kern.vt.fb.modes.HDMI-A-1
[drm]   - kern.vt.fb.default_mode
[drm] Connector VGA-1: get mode from tunables:
[drm]   - kern.vt.fb.modes.VGA-1
[drm]   - kern.vt.fb.default_mode
[drm] Connector LVDS-1: get mode from tunables:
[drm]   - kern.vt.fb.modes.LVDS-1
[drm]   - kern.vt.fb.default_mode
[drm] radeon atom DIG backlight initialized
[drm] Radeon Display Connectors
[drm] Connector 0:
[drm]   HDMI-A-1
[drm]   HPD1
[drm]   DDC: 0x6530 0x6530 0x6534 0x6534 0x6538 0x6538 0x653c 0x653c
[drm]   Encoders:
[drm]     DFP1: INTERNAL_UNIPHY2
[drm] Connector 1:
[drm]   VGA-1
[drm]   HPD2
[drm]   DDC: 0x6540 0x6540 0x6544 0x6544 0x6548 0x6548 0x654c 0x654c
[drm]   Encoders:
[drm]     CRT1: INTERNAL_UNIPHY2
[drm]     CRT1: NUTMEG
[drm] Connector 2:
[drm]   LVDS-1
[drm]   HPD3
[drm]   DDC: 0x6550 0x6550 0x6554 0x6554 0x6558 0x6558 0x655c 0x655c
[drm]   Encoders:
[drm]     LCD1: INTERNAL_UNIPHY
[drm]     LCD1: TRAVIS
[drm] fb mappable at 0xC03DA000
[drm] vram apper at 0xC0000000
[drm] size 4325376
[drm] fb depth is 24
[drm]    pitch is 5632
VT: Replacing driver "efifb" with new "fb".
start FB_INFO:
type=11 height=768 width=1366 depth=32
cmsize=16 size=4325376
pbase=0xc03da000 vbase=0xfffff800c03da000
name=drmn0 flags=0x0 stride=5632 bpp=32
cmap[0]=0 cmap[1]=7f0000 cmap[2]=7f00 cmap[3]=c4a000
end FB_INFO
drmn0: fb0: radeondrmfb frame buffer device
[drm] Initialized radeon 2.50.0 20080528 for drmn0 on minor 0
lo0: link state changed to UP
re0: link state changed to DOWN
re0: link state changed to UP
hdac1: <ATI (0x9902) HDA Controller> mem 0xfeb44000-0xfeb47fff at device 1.1 on pci0
hdac1: hdac_get_capabilities: Invalid corb size (0)
device_attach: hdac1 attach returned 6
intsmb0: <AMD FCH SMBus Controller> at device 20.0 on pci0
smbus0: <System Management Bus> on intsmb0
ums0 on uhub3
ums0: <Logitech USB Receiver, class 0/0, rev 2.00/12.03, addr 1> on usbus0
ums0: 16 buttons and [XYZT] coordinates ID=2
uhid0 on uhub3
uhid0: <Logitech USB Receiver, class 0/0, rev 2.00/12.03, addr 1> on usbus0
