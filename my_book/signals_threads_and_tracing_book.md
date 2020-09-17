Handson about signals, threads and tracing them with Linux
==========================================================


What`s this book about?
-----------------------

Das Buch soll ein praktischer Leitfaden zum Einsatz von Signalen in Multithreaded Applikations sein. Ein besonderes Merkmal ist dabei das Tracing und die Analyse der Vorgänge anhand von konkreten Beispielen. Ziel ist es nicht eine tiefgehende Erklärung und Herleitung von Signalen und Threads zu geben. Dafür gibt es bereits hervorrangede Bücher von Stevens/Rago/Kerrisks/Butenhof. Hier geht es um den praktischen Einsatz und die sinnvolle Anwendung von Signalen in Multithreaded Applikations.
Der Einsatz von Signale in Multiprosses Applikations wird nur am Rande beschrieben. Hier verweise ich auf die bereits oben genannte Werke.


Overview signals
----------------
...


Overview threads
----------------
...


Overview tracing
----------------
...


Examples
--------

- simple examples to measure signals and threads
- 4 threads wich change the disposition during runtime and show the resulting chaos
- setup explicit thread for common signal handling
- setup explicit thread for common signal handling and change SIGUSR1 to different dispositions in 4 different threads ...

- Konkretes Beispiel -> baalued/baalue



----

- restart von threads
- resume von threads
- steuerung von Aktionen/Verhalten mittels SIGUSR1 und SIGUSR2