
/*		Die initPlayerLocal.sqf
 *
 * Die initPlayerLocal.sqf wird auf dem Computer jedes Spielers zu Missionsstart ausgeführt.
 * Zusätzlich wird sie auf den Computern von Spielern ausgeführt, die JIPen,
 * also nach dem Start einer Mission die Mission betreten.
 * Daher eignet sie sich hervorragend für Briefing und Loadout.
 *
 * BIS stellt zwei Variablen zur Verfügung:
 *	_this select 0 - diese Variable enthält den Spieler, der diese Datei ausführt. Trivial, da player das selbe tut.
 *	_this select 1 - diese Variable ist true / false, je nachdem, ob es sich um JIP handelt, eine sehr praktische Variable.
 *
 * Weitere Informationen findet ihr hier:
 *		https://community.bistudio.com/wiki/Initialization_Order
 *		https://community.bistudio.com/wiki/Event_Scripts
 */

/* W_FRAMEWORK OPTIONEN - LOADOUTS */

// Keine Karte? Wenn Spieler keine Karte im Spiel verwenden dürfen, dann kannst du das über folgende Bedingung einstellen. Einfach den Booleschen Ausdruck hinschreiben und fertig!
//#define NO_MAP_CONDITION      rank player == "PRIVATE"

// Der #include Befehl fügt Dateien ein, so als wäre deren Inhalt hier geschrieben.
// Er wird nur einmal beim erstens Ausführen einer Datei aufgerufen.
// Hier werden alle Standards eingefügt, das ist nicht weiter wichtig für dich.
#include "W_FRAMEWORK\initPlayerLocal.sqf"
// Hier wird das Briefing eingefügt
#include "briefing.sqf"

// Hier wird ausgestellt, dass Spieler Feindmeldungen automatisch "rausbrüllen".
enableSentences false;
