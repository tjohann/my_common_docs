Echtzeit und Echtzeit-OSe
=========================

Ein Echtzeit-System ist dadurch gekennzeichent, dass die Gültigkeit einer Berechnung/Statuses abhängig von der Zeit ist.
Beispiel: Bei einem Ottomotor (https://de.wikipedia.org/wiki/Ottomotor) ist der Zeitpunkt für das Auslösen des Zündfunkens von entscheidender Bedeutung. Abhängig von der Position des Kolbens darf die Zündung nur um den oberen Totpunkt erfolgen. Bei einem Mehrzylinder Ottomotor müssen die Auslösung über die einzelnen Zylinder in einem bestimmten Verhältnis erfolgen.
Das Beispiel des Ottomotors zeigt, dass das Auslöse-Kommando zum richtigen Zeitpunkt erfolgen muss. Kommt das Kommando zu früh oder zu spät kann es neben der Verletzung der Abgasnorm auch zu irreperablen mechanischen Schäden kommen.
Ein weiteres Beispiel ist die Sensorik in einem Reaktordruckbehälter eines Kernkraftwerkes (https://de.wikipedia.org/wiki/Druckwasserreaktor). Diese messen Umweltdaten, die die Basis für die Enscheidung der automatischen Schutzmechanismen bei einem Störfall sind. Kommen die Daten nicht zum richtigen Zeitpunkt, dann ist die komplette Sensorik zerstört und der notwendige Input fällt aus.

Wichtig bei der Thematik ist zu erkennen, dass nicht das Ergebnis eine Funktion der Zeit ist, sondern die Gültikeit. Die physikalischen Größen oder Statuswerte können korrekt sein, wenn sie jedoch zum falschen Zeitpunkt zur Verfügung stehen, sind sie "wertlos".


Hard/Soft Echtzeit Systems
--------------------------

Das Beispiel des Ottomotors bzw. der Reaktordruckbehälter-Sensorik zeigen, dass die Folgen eines Verfehlens der Deadline (*Letzter Zeitpunkt an dem die Werte vorhanden sein müssen, bzw. eine Reaktion zu erfolgen hat) schwerwiegende Folgen haben. In diesem Fall wird von harter Echzeit gesprochen. Im Gegensatz dazu gibt es weiche Echtzeit. Die Klassifizierung nach harter und weicher Echzeit erfolgt anhand der Folgen des Verletzens der Deadline. Als Beispiel für weiche Echtzeit kann eine Telefon-Verbindung gesehen werden. Wenn es bei der Kommnunikation zu Ausfällen bzw. Verlängerungen kommt sind die Folgen gering. Bei größeren "Lücken" wird der Satz vom Sprecher einfach wiederholt. Das wäre bei der Reaktordruckbehälter-Sensorik nicht mehr möglich. In vielen Anwendungen ist es nicht möglich bzw. nicht notwendig so klar zwischen hard und soft zu unterscheiden (* hard, firm und soft).


Reliable Systems
----------------

Ein weiterer wichtiger Punkt, der sehr häufig mit Echtzeit-Systemen in Verbindung gebracht wird ist Safety. Safety umschreibt die gesamte Thematik Vertrauenswürdigkeit. Bei einem Röntgengerät vertrauen sowohl der Patient, als auch der Arzt darauf, dass die Röntgenröhre (https://de.wikipedia.org/wiki/R%C3%B6ntgenr%C3%B6hre) nur so lange angesteuert wird, wie es wirklich notwendig ist. In der Anfangszeit dieser Technologie hat der Arzt die Dauer der Bestrahlung durch einen Handtaster selbst bestimmt. Bei heutigen Systemen macht das das Steuerungssystem. Damit solche Systeme das automatisch (* "eigenständig") machen, sind entsprechende Sicherheitskonzepte in Hardware und Software notwendig. Ein klassisches Beispiel ist die Reaktion auf Fehler. Hier ist relevant welche Arten von Fehlern z.B. bei einem Sensor auftreten können. Anhand der Fehlerarten und der entsprechenden Sensorik können z.B. Ersatzreaktionen erfolgen. Bei einem System mit mehreren Temperatursensoren könnte die fehlende Temperatur z.B. über ein Modell aus den anderen vorhandenen Werten berechnet werden. In diesem Kontext kommt auch der Bergriff Quality of Service zur Geltung. Anhand der Eigenschaften eines Wertes/Status kann die Genauigkeit und sogar Level of Trust mittransportiert werden (* dies hat bei der Implementierung zur Folge, dass eine Temperatur nicht mehr ein uint8 ist, sondern ein struct {uint 8 value; uint8 reliability_level}). Abhängig von der Schwere des Fehlers können auch ganze Subsysteme abgeschaltet werden. Ein Ausfall der Raddrehzahl-Sensoren bei einem ESP Steuergerät (https://de.wikipedia.org/wiki/Fahrdynamikregelung) führt nicht dazu, dass die Bremsfunktion nicht mehr nutzbar ist.

Diese allgemeine Betrachtung führen zu einem System, welches unterschiedliche Arbeitsmodies haben, die abhängig von Fehlern und Unplausibilitäten aktiviert werden und entsprechende Teilfunktionalitäten z.B. abschalten.


Embedded Systems
----------------

Viele technische Lösungen des Alltags sind kombinationen aus Entwicklungen verschiedener Disziplinen. Ein Smartphone besteht aus Elektronik (* Elektrotechnik) und der Software (* Informatik) die wir nutzen. Bei einem komplexen Röntgengerät kommt noch die Mechanik (* Maschinenwesen) und Medizin dazu. Solche Systeme werden aus Sicht der Software embedded Systems genannt. Hier spielt die Software im Gegensatz zu einer Textverarbeitung nicht die "Hauptrolle", sondern ist Teil des Gesamtsystems. In vielen Fällen ist die Software nur eine Art Vehicle um die eigentlich Funktionalität darzustellen. Ein typisches Beispiel ist der Ottomotor. Hier stellt die Software einen erheblichen Teil der Funktionalität dar, aber der Nutzer benötigt einen Motor, sprich das mechanische Gebilde. Aufgrund dessen unterliegen gerade die sekundären Teilcompononeten einem enormen Kostendruck (* welchen Vorteil sollte eine gute Software-Architektur für den Betrieb des Motors haben?).


Operation Systems
-----------------

Ein Betriebssystem stellt die Schnittstelle zwischen der Applikation und der Hardware dar. Als solche hat es einen erheblichen Einfluß auf die Leistungsfähigkeit des Gesamtsystems. Um auch Software-Komponenten wieder verwenden zu können, bedarf es einer durchdachten Aufteilung innerhalb devices (* die elektronische Kontrolleiheit).
Im allgemeinen stellt das Betriebssystem Dienste/Services für die Applikation zur Verfügung. Ein Beispiel hierfür ist der Scheduler oder zugriffe auf Sensorik (* incl. signal conditioning -> Spannung in z.B. Temperatur in Kelvin umwandeln).


Echtzeit-OSe
------------

Ein Echtzeit-OS stellt zusätzliche, bzw. optimierte Dienste zur Verfügung. Wie bereits im Vorfeld beschrieben, bedarf es abhängig von Fehlern oder Unplausibilitäten entsprechende Arbeitsmodies. Ein weitere wichtiger Punkt ist die Zeitbasis und deren Genauigkeit und die Unterbrechbarkeit von von Code.

Im weiteren werden die wichtigen Punkte in einer Beispiel-Implementierung hergeleitet und beschrieben (https://github.com/tjohann/miblos).
