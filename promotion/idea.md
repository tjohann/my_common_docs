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




Themenspeicher:
---------------

- FreeRTOS
- Zyphr


Literatur:
----------

- https://www.amazon.de/Hardware-Beschleunigung-eines-Echtzeitbetriebssystems-Beispiel-FreeRTOS/dp/3330507527/ref=sr_1_22?ie=UTF8&qid=1492841400&sr=8-22&keywords=echtzeitbetriebssysteme
- https://www.amazon.de/Real-Time-Systems-Design-Analysis-Practitioner/dp/0470768649/ref=pd_sbs_14_2?_encoding=UTF8&psc=1&refRID=7291X3JDG1S6J3KN06M5
- https://www.amazon.de/Real-Time-Embedded-Systems-Principles-Engineering/dp/0128015071/ref=pd_sbs_14_3?_encoding=UTF8&psc=1&refRID=7291X3JDG1S6J3KN06M5
- https://www.amazon.de/Real-Time-Software-Design-Embedded-Systems/dp/1107041090/ref=pd_sbs_14_2?_encoding=UTF8&psc=1&refRID=X14J823JN85SAF5E5K6N
- https://www.amazon.de/Real-Time-Concepts-Embedded-Systems-Qing/dp/1578201241/ref=sr_1_1?s=books-intl-de&ie=UTF8&qid=1492847994&sr=1-1&keywords=Real-Time+Concepts+for+Embedded+Systems


Ausgeliehen DD
- https://www.amazon.de/Echtzeitsysteme-Grundlagen-Funktionsweisen-Anwendungen-eXamen-press-ebook/dp/B00Q8LL82Y/ref=sr_1_7?ie=UTF8&qid=1492841327&sr=8-7&keywords=echtzeitbetriebssysteme
- https://www.amazon.de/Real-Time-Systems-Principles-Distributed-Applications/dp/1441982361/ref=asap_bc?ie=UTF8



Paper:
------

- http://www.ni.com/white-paper/3938/de/
- http://www.ni.com/white-paper/14238/en/