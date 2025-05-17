<?php

// GET-request
$ch = curl_init('https://jsonplaceholder.typicode.com/posts/1');
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
$response = curl_exec($ch);
curl_close($ch);

echo "GET Response:\n" . $response . "\n\n";



// POST-request
$postData = [
    'title' => 'COOLEST TITLE',
    'body' => 'GREATEST BODY',
    'userId' => 1
];

$ch = curl_init('https://jsonplaceholder.typicode.com/posts');
curl_setopt_array($ch, [
    CURLOPT_POST => true,
    CURLOPT_POSTFIELDS => $postData,
    CURLOPT_RETURNTRANSFER => true,
]);
$response = curl_exec($ch);
curl_close($ch);

echo "POST Response:\n" . $response . "\n\n";



// PUT-request
$putData = [
    'id' => 1,
    'title' => 'UPDATED TITLE',
    'body' => 'UPDATED BODY',
    'userId' => 1
];

$ch = curl_init('https://jsonplaceholder.typicode.com/posts/1');
curl_setopt_array($ch, [
    CURLOPT_CUSTOMREQUEST => 'PUT',
    CURLOPT_POSTFIELDS => $putData,
    CURLOPT_RETURNTRANSFER => true,
]);
$response = curl_exec($ch);
curl_close($ch);

echo "PUT Response:\n" . $response . "\n\n";



// DELETE-request
$ch = curl_init('https://jsonplaceholder.typicode.com/posts/1');
curl_setopt_array($ch, [
    CURLOPT_CUSTOMREQUEST => 'DELETE',
    CURLOPT_RETURNTRANSFER => true,
]);
$response = curl_exec($ch);
curl_close($ch);

echo "DELETE Response:\n" . $response . "\n\n";

?>