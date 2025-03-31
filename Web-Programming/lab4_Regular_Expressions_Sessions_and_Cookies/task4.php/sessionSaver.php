<?php

session_start();
$_SESSION["name"] = $_POST["name"];
$_SESSION["subject"] = $_POST["subject"];
$_SESSION["experience"] = $_POST["experience"];
echo "Данные сохранены в сессии";

?>
