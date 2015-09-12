
/*
 *		Die initPlayerServer.sqf
 *
 * Die initPlayerServer.sqf wird für jeden Spieler immer dann ausgeführt, wenn dieser Spieler
 * die Mission startet, also am Anfang oder bei JIP.
 *
 * BIS stellt zwei Variablen zur Verfügung:
 *	_this select 0 - diese Variable enthält den Spieler, der diese Datei ausführt.
 *	_this select 1 - diese Variable ist true / false, je nachdem, ob es sich um JIP handelt, eine sehr praktische Variable.
 *
 * Weitere Informationen findet ihr hier:
 *		https://community.bistudio.com/wiki/Initialization_Order
 *		https://community.bistudio.com/wiki/Event_Scripts
 */