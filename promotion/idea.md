Idee für Promotions-Thema
=========================


Teil 1
------

Erarbeitung der theoretischen Grundlagen für Echtzeitsysteme, speziell Echtzeit-Betriebssysteme und definieren von entsprechenden Bewertungskriterien und deren Messungmethoden.

Themen:
- Grundlagen Echtzeit-Systeme
- Anforderungen an Echtzeit-Betriebssysteme
  - Wie erfülle ich diese Anforderungen?
- RTOS (Bare-Metal)
  - Klassische RTOS (Event + Time-triggert)
  - Time-triggert Systeme
- Full-Flavored OS
  - Linux
  - RT-PREEMPT
- Hypervisor
  - Typen/Grundlagen
  - Einfluß auf Echtzeitverhalten?
  - Jailhouse (https://github.com/siemens/jailhouse)
- Bewertungskriterien
- Definition der Messmethoden
- Safety (SILx)


Teil 2
------

Implementierung eines einfachen Single-Code-Bare-Metal RTOS (Event + Time-triggert) -> MIBLOS (https://github.com/tjohann/miblos).
Device: Cortex-M3/4

Themen:
- Degration/Operation-Modes
- Event triggert
- Time triggert
- Praktische Messmethoden
- SIL ... (?)


Teil 3
------

Analyse und Bewertung des RT-PREEMPT gepatchten Linux-Kerns.
Device: Cortex-A7/15 (Dual-Core)

Themen:
- Degration/Operation-Modes
- Event triggert
- Time triggert
- Multicore (?)
- Praktische Messmethoden
- SIL ... (?)


Teil 4
------

Analyse und Bewertung der Kombination (Linux + Jailhouse) + Linux-PR-PREEMPT + MIBLOS
Device: Cortex-A7/15 (Quad-Core)

Themen:
- Degration/Operation-Modes
- Kommunikations-Methoden zwischen den einzelnen Cellen
- Beinflußung/Seperation der Cellen
- Praktische Messmethoden
- SIL ... (?)


Teil 5
------

Welche Möglichkeiten bieten FPGA-basierte Softcore Systeme als problem-optimierte Systeme?
Device: Cyclone XX

Themen:
- RT optimierter Softcore