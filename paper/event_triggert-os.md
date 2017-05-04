Event-Triggert OS
=================


Overview
--------

Bei einem Event-Triggert OS werden alle Aktionen durch einen Event (* Interrupt) ausgelöst. Ein Beenden des sampenls eines AD Wertes führt zu einen Interrupt der die Verarbeitungskette auslöst. Unterschiedliche Ereignisse (* z.B. Ausfall eines Sensors oder das Überschreiten eines Grenzwertes) führen ebenfalls zum Auslösen eines (Soft)-Interrupts. Das Hauptproblem bei dieser Architektur ist, dass ich die Auslastung des Prozessors nur bedingt verhersagen werden kann da die meisten Interrupts asynchron sind. Ist die Anzahl der Eventquellen significant hoch, dann kann es sogar soweit kommen, dass der Prozessor nur noch mit dem Aufrufen von Interrupts und der Abarbeitung der (meist kurzen) Handler beschäftigt ist. Dann ist eine präziese Vorhersage der Laufzeit oder Antwortzeiten so gut wie nicht mehr möglich. Aus diesem Grund findet man eher selten reine Event-Triggert Systeme. In den meisten Anwendungen handelt es sich bei dem Betriebssytem um eine Kombination aus Event- und Time-Triggert basierten Ansetzen.

Im Repository findet sich ein einfaches Event-Triggert-OS für Atmel AVR Controller welches für die Drehzahlregelung eines DC-Motors genutzt wird.

TODO: Link ....
