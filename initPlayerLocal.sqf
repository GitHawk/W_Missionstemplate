
/*      Die initPlayerLocal.sqf
 *
 * Die initPlayerLocal.sqf wird auf dem Computer jedes Spielers zu Missionsstart ausgeführt.
 * Zusätzlich wird sie auf den Computern von Spielern ausgeführt, die JIPen,
 * also nach dem Start einer Mission die Mission betreten.
 * Daher eignet sie sich hervorragend für Briefing und Loadout.
 *
 * BIS stellt zwei Variablen zur Verfügung:
 *  _this select 0 - diese Variable enthält den Spieler, der diese Datei ausführt. Trivial, da player das selbe tut.
 *  _this select 1 - diese Variable ist true / false, je nachdem, ob es sich um JIP handelt, eine sehr praktische Variable.
 *
 * Weitere Informationen findet ihr hier:
 *      https://community.bistudio.com/wiki/Initialization_Order
 *      https://community.bistudio.com/wiki/Event_Scripts
 */

// Der #include Befehl fügt Dateien ein, so als wäre deren Inhalt hier geschrieben.
// Hier wird das Briefing eingefügt
#include "briefing.sqf"

// Hier wird ausgestellt, dass Spieler Feindmeldungen automatisch "rausbrüllen"
enableSentences false;
