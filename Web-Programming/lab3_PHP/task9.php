<?php
function arrayXFiller($array): array {
    for ($i = 0; $i < count($array); $i++) {
        $array[$i] = str_repeat("x", $i + 1);
    }
    return $array;
}

$array1 = [6, 7, 8, 453, 134];
$array1 = arrayXFiller($array1);
foreach ($array1 as $element) {
    echo $element . " ";
}
echo "\n";



function arrayFill($value, $length): array {
    $array = [];
    for ($i = 0; $i < $length; $i++) {
        $array[$i] = $value;
    }
    return $array;
}
foreach (arrayFill(69, 13) as $element) {
    echo $element . " ";
}
echo "\n";



function sumOfTwoDimensionalArray($array): int {
    $sum = 0;

    for ($i = 0; $i < count($array); $i++) {
        for($j = 0; $j < count($array[$i]); $j++) {
            $sum += $array[$i][$j];
        }
    }

    return $sum;
}

$twoDimensionalArray = [[1, 2, 3], [4, 5], [6]];
echo sumOfTwoDimensionalArray($twoDimensionalArray) . "\n";



$array2 = [];

for ($i = 0; $i < 3; $i++) {
    for ($j = 1; $j <= 3; $j++) {
        $array2[$i][$j] = $i * 3 + $j;
    }
}

foreach ($array2 as $subarray) {
    foreach ($subarray as $element) {
        echo $element . " ";
    }
    echo "\n";
}
echo "\n";



$array3 = [2, 5, 3, 9];
$result = $array3[0] * $array3[1] + $array3[2] * $array3[3];
echo $result . "\n";



$user = ["name" => "Nikita", "surname" => "Filatov", "patronymic" => "Andreevich"];
echo $user['surname'] . ' ' . $user['name'] . ' ' . $user['patronymic'] . "\n";



$date = ['year' => date('Y'), 'month' => date('F'), 'day' => date('d')];
echo $date['year'] . '-' . $date['month'] . '-' . $date['day'] . "\n";



$array4 = ['a', 'b', 'c', 'd', 'e'];
echo count($array4) . "\n";
echo $array4[count($array4) - 1] . "\n";
echo $array4[count($array4) - 2] . "\n";