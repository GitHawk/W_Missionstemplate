params ["_name"];

private _message = format ["Fehler im W Template: Dem Spieler %1 fehlt mindestens ein DLC!",_name];
systemChat _message;
diag_log _message;
