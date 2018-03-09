<html>
<?php
$nombre = $_POST['nombre'];
$mail = $_POST['mail'];
$mensaje = $_POST['mensaje'];
$empresa = "Jadim inc.";
$remitente = "xavierescobar3335@gmail.com";
$contraseña = "bringmetolife";


require_once('phpmailer/class.phpmailer.php');
 
$correo = new PHPMailer();
 
$correo->IsSMTP();
 
$correo->SMTPAuth = true;
 
$correo->SMTPSecure = 'tls';
 
$correo->Host = "smtp.gmail.com";
 
$correo->Port = 587;
 
 
 
$correo->Username   = $remitente;
 
$correo->Password   = $contraseña;
 
$correo->SetFrom($remitente, $empresa);
 
$correo->AddReplyTo($remitente,$empresa);
 
$correo->AddAddress($mail, $nombre);
 
$correo->Subject = "Consulta";
 
$correo->MsgHTML($mensaje);
 
 
if(!$correo->Send()) {
  echo "Hubo un error: " . $correo->ErrorInfo;
} else {
  echo "Mensaje enviado con exito.";
}




?>

</html>