<?php

function redirectToHome() {
    header("Location: /");
    exit();
}

if (!isset($_POST['email'], $_POST['category'], $_POST['title'], $_POST['description'])) {
    redirectToHome();
}

$email       = $_POST['email'];
$category    = $_POST['category'];
$title       = $_POST['title'];
$description = $_POST['description'];
$mysqli = new mysqli('localhost', 'root', 'helloworld', 'web', 6603);

if (mysqli_connect_errno()) {
    printf("Connection to the MySQL server is not possible. Error code: %s\n", mysqli_connect_error());
    redirectToHome();
}

$stmt = $mysqli->prepare('INSERT INTO ad (email, category, title, description) VALUES (?, ?, ?, ?)');

$stmt->bind_param('ssss', $email, $category, $title, $description);

if (!$stmt->execute()) {
    throw new Exception('Insertion error in the database: ' . $stmt->error);
}

$stmt->close();
$mysqli->close();

redirectToHome();