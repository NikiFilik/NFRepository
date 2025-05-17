<?php

class ApiClient {
    private $baseUrl;
    private $headers;

    public function __construct($baseUrl, $headers = []) {
        $this->baseUrl = rtrim($baseUrl, '/');
        $this->headers = $headers;
    }

    private function sendRequest($method, $endpoint, $data = null) {
        $url = $this->baseUrl . $endpoint;
        
        $ch = curl_init($url);
        $options = [
            CURLOPT_RETURNTRANSFER => true,
            CURLOPT_HTTPHEADER => $this->headers,
            CURLOPT_FOLLOWLOCATION => true
        ];

        if ($method === 'POST') {
            $options[CURLOPT_POST] = true;
            $options[CURLOPT_POSTFIELDS] = $data;
        } 
        elseif ($method !== 'GET') {
            $options[CURLOPT_CUSTOMREQUEST] = $method;
            $options[CURLOPT_POSTFIELDS] = $data;
        }

        curl_setopt_array($ch, $options);
        $response = curl_exec($ch);

        if (curl_errno($ch)) {
            throw new Exception(curl_error($ch));
        }

        $httpCode = curl_getinfo($ch, CURLINFO_HTTP_CODE);
        curl_close($ch);

        if ($httpCode >= 400) {
            throw new Exception("HTTP $httpCode", $httpCode);
        }

        return json_decode($response, true);
    }

    public function get($endpoint, $params = []) {
        $endpoint .= '?' . http_build_query($params);
        return $this->sendRequest('GET', $endpoint);
    }

    public function post($endpoint, $data) {
        return $this->sendRequest('POST', $endpoint, $data);
    }

    public function put($endpoint, $data) {
        return $this->sendRequest('PUT', $endpoint, $data);
    }

    public function delete($endpoint) {
        return $this->sendRequest('DELETE', $endpoint);
    }
}

// Usage example with OpenWeatherMap
$apiKey = 'YOUR API KEY';
$client = new ApiClient('https://api.openweathermap.org/data/2.5', [
    'Accept: application/json',
]);
try {
    $weather = $client->get('/weather', [
        'q' => 'Kaliningrad',
        'appid' => $apiKey,
        'units' => 'metric'
    ]);
    print_r($weather);
} 
catch (Exception $e) {
    echo "Error fetching weather: " . $e->getMessage();
}

?>