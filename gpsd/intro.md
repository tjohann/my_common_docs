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


GPRMC data
----------

Example (taken from https://circuitdigest.com/microcontroller-projects/reading-gps-data-using-computer-and-arduino)


$GPRMC,123519.000,A, 7791.0381,N, 06727.4434,E,022.4,084.4,230394,003.1,W*6A
$GPRMC,HHMMSS.SSS,A,latitude,N,longitude,E,speed,angle,date,MV,W,CMD


Description:
$GPRMC -> Recommended Minimum sentence C
HHMMSS.SSS -> Time in hour minute seconds and milliseconds format.
A -> Status // A=active and V= void
Latitude -> Latitude 49 deg. 16.45 min. North
N -> Direction N=North, S=South
Longitude -> Longitude(Coordinate)
E -> Direction E= East, W=West
Speed -> speed in knots
Angle -> Tracking angle in degrees
Date -> Time stamp (Date in UTC)
MV -> Magnetic Variation
W -> Direction of variation E/W
CMD (*6A) -> Checksum Data


NMEA and more
-------------

http://aprs.gids.nl/nmea/

ntrip:
https://igs.bkg.bund.de/ntrip/about

dgps-ip:
http://www.freebsdsoftware.org/astro/dgpsip.html


links
-----

http://www.trimble.com/gps_tutorial/


projects
--------

https://circuitdigest.com/microcontroller-projects/vehicle-tracking-system-using-arduino-gps-and-gsm
