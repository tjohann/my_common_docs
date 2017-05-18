some basic infos around gps
===========================


"Needed infos":
three coordinates and clock deviation from satellite time

"Output" with 4+ satellites:
latitude, longitude and height relative to mean sea level of the actual location
"Output" with 3 satellites:
latitude, longitude

"Frequency":
1176MHz ... 1600 MHz

"Data":
GPGGA -> Global Positioning System Fix Data -> coordinates ... time and more useful information


GPGGA data
----------

Example (taken from https://circuitdigest.com/microcontroller-projects/reading-gps-data-using-computer-and-arduino)


$GPGGA,104534.000,7791.0381,N,06727.4434,E,1,08,0.9,510.4,M,43.9,M,,*47
$GPGGA,HHMMSS.SSS,latitude,N,longitude,E,FQ,NOS,HDP,altitude,M,height,M,,checksum data

Description:
$GPGGA -> Global Positioning system fix data
HHMMSS.SSS -> Time in hour minute seconds and milliseconds format.
latitude -> Latitude (Coordinate)
N -> Direction N=North, S=South
longitude -> Longitude(Coordinate)
E -> Direction E= East, W=West
FQ -> Fix Quality Data
NOS -> No. of Satellites being Used
HPD -> Horizontal Dilution of Precision
altitude -> Altitude from sea level
M -> Meter
height ... like Altitude
	

NMEA
----

http://aprs.gids.nl/nmea/


projects
--------

https://circuitdigest.com/microcontroller-projects/vehicle-tracking-system-using-arduino-gps-and-gsm
