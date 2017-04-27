A Time-Triggert-OS implementation
=================================


Overview
--------

Ein Time-Triggert OS besteht im groben aus einem zentralen Timer, der bei Überlauf einen Interrupt auslöst. In dem Interrupt-Handler wird ein Scheduler/Dispatcher "aufgerufen", der dann über einen Tabelle von aufzurufenden Funktionen iteriert und dann wieder einschäft.
