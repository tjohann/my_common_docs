A Time-Triggert-OS implementation
=================================


Overview
--------

Ein Time-Triggert OS besteht im groben aus einem zentralen Timer, der bei Überlauf einen Interrupt auslöst. In dem Interrupt-Handler wird ein Scheduler/Dispatcher "aufgerufen", der dann über einen Tabelle von aufzurufenden Funktionen iteriert und dann wieder einschläft.

Bei einem verteilten System von einzelnen Clustern ist die Frage der Genauigkeit des Zeitstrahles und die Synchronität über die unterschiedlichen Cluster hinweg sehr wichtig. Um z.B. bei Reihenfolge von Events den Auslöser herrauszufinden wird häufig ein Timestamp dem Event hinzugefügt. Sind alle Zeitgeber synchron kann allein durch den Zeitstempel die Reihenfolge der Events analysiert werden und die Rootcause zuverlässig bestimmt werden. Sind jedoch die Zeitbasen unterschiedlich stimmen die Timestamps nicht mit dem realen Auftreten entlang des Zeitstrahls überein, Somit kann es recht schnell zu Fehldeutungen kommen. Ein recht einfacher Weg diese Gefahr einzuschränken ist das Auftreten von Events nur in bestimmten Zeitintervallen zuzulassen. Natürlich lösst es nicht das Problem der unterschiedlichen Zeibasen reduziert aber den absoluten Zeitfehler und ermöglicht eine Korrektur durch das Messen des Zeitversatzes zum Fensterbeginn.


 |         |  |          |
 -------------------------
         /     \
       Zeitfenster


 |         |  |          |
 -------------------------
         '  '
         | |
		/   \
	Zeitdifferenz

Vorraussetzung dafür ist allerdings ein relativ kleines Fenster und die Annahme das der sendende Cluster gleich zu Beginn des Fensters seine Events an den auswertenden Cluster sendet (* und das die Zeitbasis im auswertenden Cluster valide ist).


Generell lässt sich dieser Ansatz auch auf einem einzelnen Device umsetzen. Das Zeitfenster ist hierbei representiert durch einen Prozess/Task der alle möglichen Events liest. Die Events müssen dann allerdings zwischen gespeichert werden und zu dem Lesezeitpunkt valid sein. Im Rahmen von Miblos und der RT-PREEMPT Untersuchung (* Linux Kernel mit RT-PREEMPT Patch) wird ein solches System implementiert. Abhängig von der Quelle wird z.B. ein Interrupt ausgelöst wenn ein ADC Wert komplet gesampelt wurde. Die IRQ-Service-Routine kopiert nur den Registerwert in eine globale Variable, die dann am Anfang der Prozess-/Taskkette gelesen werden kann.
