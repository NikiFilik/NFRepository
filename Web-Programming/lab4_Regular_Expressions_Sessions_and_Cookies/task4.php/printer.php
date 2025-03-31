<?php

session_start();
if (isset($_SESSION["name"]) && isset($_SESSION["subject"]) && isset($_SESSION["experience"])) {
    $name = $_SESSION["name"];
    $subject = $_SESSION["subject"];
    $experience = $_SESSION["experience"];
    echo "Имя преподавателя: $name <br> Предмет: $subject <br> Стаж: $experience";
}

?>