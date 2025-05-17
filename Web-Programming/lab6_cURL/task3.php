<?php

function CURLrequest($url, $method = 'GET', $data = null, $headers = []) 
{
    $ch = curl_init($url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_HEADER, false);

    if ($method === 'POST') {
        curl_setopt($ch, CURLOPT_POST, true);
    } 
    elseif (in_array($method, ['PUT', 'DELETE'])) {
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, $method);
    }

    if ($data !== null) {
        if (is_array($data)) {
            $data = json_encode($data);
            $headers[] = 'Content-Type: application/json';
        }
        curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
    }

    if (!empty($headers)) {
        curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
    }

    $response = curl_exec($ch);
    $error = curl_error($ch);
    $code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
    curl_close($ch);

    if ($error) {
        return "Request error: $error\n";
    } 
    elseif ($code >= 400) {
        return "HTTP error, code: $code\n Response: $response\n";
    } 
    else {
        $data = json_decode($response, true);
        print_r($data);
        return "Success\n";
    }
}

echo "Success request: " . CURLrequest('https://jsonplaceholder.typicode.com/posts/1') . "\n";
echo "Error 404: " . CURLrequest('https://jsonplaceholder.typicode.com/posts/noob'). "\n";
echo "cURL error: " . CURLrequest('https://worstdomain.bad') . "\n";

?>