Linux als Realtime-OS
---------------------

....


Time-triggert
-------------

siehe https://github.com/tjohann/time_triggert_env



Event-triggert
--------------

- HW-Events via Kernel-Treiber und blocking-IO ... eventuell auch aio signals ...
- Andere Events via aio signals.



Kombination
-----------

Implementierung von event-basiertem Ansatz (HW-Events) mittels Kernel Treiber und blocking-IO in seperaten Thread der eine globale Variable beschreibt. Time-triggert Environment liest dann entsprechend dem zyklischen Zeitsystem.