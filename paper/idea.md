Idee für Paper-Thema
====================


Grundidee/Motivation
--------------------

Echtzeit Systeme sind eine komplexe und nicht unbedingt einfach zu verstehende Thematik der Elektrotechnik/technischen Informatik. Viele der notwendingen Betrachtungen erschließen sich erst auf den zweiten oder dritten Blick. Desweiteren sind die notwendigen Hard- und Software Komponenten meist nur schwer zu bekommen und i.d.R. properitär. Da aber ein Großteil der entwickelten/geschriebenen und verwendeten Hard- und Software Komponenten in embedded Systemen und auch sehr häufig im Echtzeitkontext laufen, besteht reges Intresse an dieser Thematik auch im nicht kommerziellen Bereich. Das Aneignen von Wissen um Echtzeit und deren Herrausforderungen ist somit eine lohnenswerte Investition für alle die in der Branche tätig sind oder tätig sein wollen.

Die embedded Welt ist aktuell in einer tiefgreifenden Umbruchphase, die embedded typisch, eher gemächlich von statten geht. In der Vergangenheit gab es in erster Linie Bare-Metal Devices mit properitäre Betriebssystem-ähnlichen Umgebungen. Aktuell drängen aufgrund steigender Anforderungen bezüglich usablilty Full-OS'e wie Linux in den Markt. Auch in der Vergangenheit gab und gibt es Systeme mit "erweiterten" Funktionsumfang wie QNX, VxWorks oder Integraty. Diese Systeme sind jedoch alle properitär und kosten intensiv. Durch den RT-PREEMPT Patch erhält Linux echtzeitfähigkeit und kombiniert somit Full-OS typische Abstraktionen wie Filesysteme mit echtzeit typischen Funktionen wie High-Resolution-Timer um eine stabile Timeline zu haben. Auf einem Komplexitäts-Strahl befindet sich Bare-Metal und RT-PREEMPT-Linux auf den beiden entgegen gesetzten Seiten. Irgendwo zwischen diesen beiden Enden befinden sich Betriebssysteme wie FreeRTOS (http://www.freertos.org/), RTMES (http://rtems.com/) oder Zyphr (https://www.zephyrproject.org/).

Als eine Art von Hybrid kann man Hypervisor basierte Systeme ansehen. Diese bieten von beiden Welten Teilmengen für eine Applikation. Durch einen Hypervisor besteht die Möglichkeit unterschiedliche Cluster auf einer Hardware laufen zu lassen. In der aktuellen Praxis sind Bare-Metal-OSe spezielle und sehr anwendungsspezifische Implementierungen und keine Standard-OSe. Dabei handelt es sich sowohl um Time-triggert, Event-triggert als auch Kombinationen von beiden. Aus diesem Grund wird im Rahmen dieser Arbeit ein einfaches RTOS implementiert welches dann die Basis für folgende Betrachtungen ist.

Eine weitere Auffächerung der Ausprägungen stellen Prozessoren dar, die sowohl Application Kerne als auch Special/Embedded Kerne auf dem selben Die implementieren. Auch hier gibt es wieder unterschiedliche Peripherie Kerne. In der ARM Welt findet man recht häufig Kerne vom Type A7/15 und M3/4 in dem selben Prozessor, aber auch spezielle Real-Time-Kerne wie der PSP im AM335 (Beaglebone-Black) sind möglich. Alsweitere AMP Variante kommen die Big-Little Prozesoren mit einer Kombination von A15 und A7 zu nennen. Diese Kerne sind speziell für Hypervisor basierte System interresant, da sie eine bessere Korrelation zwischen Cellen Nutzlast und vorhandenem Kernen ermöglichen (Fußnote: reicht der langsamere A7 Kern für die Bare-Metal Last oder ist ein A15 notwendig?).
Speziell für Rapid-Prototyping bieten sich FPGA basierte Softcore Lösungen an, die speziell an die Anforderung angepasste Lösungen ermöglichen.

Die Idee für diese Arbeit kommt aus dem Wunsch, die einzelnen unterschiedlichen Themen, bzw System in einem kompletten Kontext zu betrachten und zu untersuchen. Ausgehend von einer Time-Triggert Bare-Metal Implementierung über RT-PREEMPT-Linux und Hypervisor-Linux-TTBare. Ziel ist es die einzelnen Vorteile, Nachteile und allgemeinen Probleme darzustellen, zu bewerten und gegebenenfalls Handlungsanweisungen zur Migration von Bare-Metal nach Hypervisor-Celle zu geben. Ein wichtiger Aspekt dieser Arbeit ist die Verwendung von Opensource im Allgemeinen und Linux im Speziellen. Sämtlicher Code und Dokumentation (incl. dieser Arbeit) sollen unter die GPLv2 bzw CC-BY-SA 2.0 gestellt werden um allen Interrsierten den Einstieg in die Thematik zu ermöglichen.

Die Arbeit gliedert sich in folgende Teile:


Teil 1
------

Erarbeitung der theoretischen Grundlagen für Echtzeitsysteme, speziell Echtzeit-Betriebssysteme und definieren von entsprechenden Bewertungskriterien und deren Messungmethoden.

Themen:
- Grundlagen Echtzeit-Systeme                         (Beginn Teil 2)
  - Begrifflichkeiten
  - ...
- Anforderungen an Echtzeit-Betriebssysteme
  - Wie erfülle ich diese Anforderungen?
  - ...
- RTOS (Bare-Metal)
  - Klassische RTOS (Event + Time-triggert)
  - Time-triggert Systeme
  - Examples: FreeRTOS, RTMES, Zyphr
                                                      (End Teil 2)
- Full-Flavored OS                                    (Beginn Teil 3)
  - Linux
  - RT-PREEMPT
  - Time triggert (Implementierung Infrastruktur im User-Space)
	(https://github.com/tjohann/time_triggert_env)
  - Event triggert (Beispiel Implementierungen mittels Kernelspace driver)
	(https://github.com/tjohann/my_driver)
                                                      (End Teil 4)
- Hypervisor                                          (Beginn Teil 4)
  - Typen/Grundlagen
  - Einfluß auf Echtzeitverhalten?
  - Example: jailhouse (https://github.com/siemens/jailhouse)
  - Clustern mittels Cluster (https://github.com/tjohann/a20_sdk)
                                                      (End Teil 4)
- FPGA basierte Ansätze                               (Beginn Teil 5)
  - Softcore Modelle
  - Optimierungen für RT-Anwendungen
  - Anbindung an Haupt-Prozessor
                                                      (End Teil 5)
- Bewertungskriterien
- Definition der Messmethoden und Messparameter
- Definition eines Usecases als praxis-orientierte Messung
- Safety (SILx)

Dauer: ~1/2 Jahr


Teil 2
------

Implementierung eines einfachen Single-Core-Bare-Metal RTOS (Event + Time-triggert) -> MIBLOS (https://github.com/tjohann/miblos).
Device: Cortex-M3/4 oder Softcore via FPGA

Themen:
- Degration/Operation-Modes
- Event triggert
- Time triggert
- Messung der wichtigesten Parameter
- Safety Betrachtungen ... (?)
- ...

Dauer: ~1/2 Jahr

[Einstieg/Übersicht](realtime-os.md)
[Time-Triggert System](time_triggert-os.md)
[Event-Triggert System](event_triggert-os.md)


Teil 3
------

Analyse und Bewertung des RT-PREEMPT gepatchten Linux-Kerns.
Device: Cortex-A7/15 (Dual-Core)

Themen:
- Degration/Operation-Modes
- Event triggert (Kernel-Space)
- Time triggert (Implementierung Infrastruktur im User-Space)
  (https://github.com/tjohann/time_triggert_env)
- Event triggert (Beispiel Implementierungen mittels Kernelspace driver)
  (https://github.com/tjohann/my_driver)
- Multicore (?)
- Messung der wichtigesten Parameter
- Safety Betrachtungen ...
- ...

Dauer: 1/2 Jahr


Teil 4
------

Analyse und Bewertung der Kombination (Linux + Jailhouse) + Linux-PR-PREEMPT + MIBLOS
Device: Cortex-A7/15 (Quad-Core)

Themen:
- MIBLOS (https://github.com/tjohann/miblos) als Bare-Metal
- Degration/Operation-Modes
- Kommunikations-Methoden zwischen den einzelnen Cellen
- Beinflußung/Seperation der Cellen
- Clustern mittels Cluster (https://github.com/tjohann/a20_sdk)
- Messung der wichtigesten Parameter
- Safety ...
- ...

Dauer: 1/2 Jahr - 3/4 Jahr

[Kombination von Linux und Bare-Metal](kombination_bare_linux.md)


Teil 5
------

Welche Möglichkeiten bieten FPGA-basierte Softcore Systeme als problem-optimierte Systeme?
Device: Cyclone XX

Themen:
- RT optimierter Softcore
- Optimierungen für RT-Anwendungen
- Anbindung an Haupt-Prozessor
- ...

Dauer: 1/2 Jahr


Teil 6
------

Auswertung und Zusammenfassung der vorrangegangenden Teile.

Themen:
- Paper
- Messtabellen/-reihen
- Erstellen einer Handlunganweisung
- ...

Dauer: 1/2 Jahr


Themenspeicher:
---------------

- FreeRTOS
- Zyphr
- RTMES
- µKernel/nanoKernel

[Others/Snippets](temp.md)


Literatur:
----------

- https://www.amazon.de/Hardware-Beschleunigung-eines-Echtzeitbetriebssystems-Beispiel-FreeRTOS/dp/3330507527/ref=sr_1_22?ie=UTF8&qid=1492841400&sr=8-22&keywords=echtzeitbetriebssysteme
- https://www.amazon.de/Real-Time-Systems-Design-Analysis-Practitioner/dp/0470768649/ref=pd_sbs_14_2?_encoding=UTF8&psc=1&refRID=7291X3JDG1S6J3KN06M5
- https://www.amazon.de/Real-Time-Embedded-Systems-Principles-Engineering/dp/0128015071/ref=pd_sbs_14_3?_encoding=UTF8&psc=1&refRID=7291X3JDG1S6J3KN06M5
- https://www.amazon.de/Real-Time-Software-Design-Embedded-Systems/dp/1107041090/ref=pd_sbs_14_2?_encoding=UTF8&psc=1&refRID=X14J823JN85SAF5E5K6N
- https://www.amazon.de/Real-Time-Concepts-Embedded-Systems-Qing/dp/1578201241/ref=sr_1_1?s=books-intl-de&ie=UTF8&qid=1492847994&sr=1-1&keywords=Real-Time+Concepts+for+Embedded+Systems
- https://www.amazon.de/Echtzeitsysteme-Grundlagen-Funktionsweisen-Anwendungen-eXamen-press-ebook/dp/B00Q8LL82Y/ref=sr_1_7?ie=UTF8&qid=1492841327&sr=8-7&keywords=echtzeitbetriebssysteme
- https://www.amazon.de/Real-Time-Systems-Principles-Distributed-Applications/dp/1441982361/ref=asap_bc?ie=UTF8
- https://www.amazon.de/Real-Time-Systems-Jane-W-Liu/dp/0130996513/ref=sr_1_1?s=books-intl-de&ie=UTF8&qid=1493137281&sr=1-1&keywords=Real-Time+Systems+Jane+Liu

- http://www.safetty.net/publications/the-engineering-of-reliable-embedded-systems-second-edition


Vorbereitung:
-------------

- https://www.amazon.de/Real-Time-Systems-Jane-W-Liu/dp/0130996513/ref=sr_1_1?s=books-intl-de&ie=UTF8&qid=1493137281&sr=1-1&keywords=Real-Time+Systems+Jane+Liu
- https://www.amazon.de/Real-Time-Systems-Principles-Distributed-Applications/dp/1441982361/ref=asap_bc?ie=UTF8


Paper/Vorlesungen:
------------------

- http://www.ni.com/white-paper/3938/de/
- http://www.ni.com/white-paper/14238/en/
- http://w3service.net/vorlesungen/embedded_systems/0020-embedded-realtime-systems/Echtzeitprogrammierung-132.pdf


TU-Dresden:
-----------

http://www.inf.tu-dresden.de/index.php?node_id=1316&ln=de
