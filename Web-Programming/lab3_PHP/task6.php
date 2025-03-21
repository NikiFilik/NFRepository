<?php
$a = 10;
$b = 3;
echo $a % $b, "\n";



if ($a % $b == 0) {
    echo "Делится ", $a / $b, "\n";
}
else {
    echo "Делится с остатком ", $a % $b, "\n";
}



$st = 2 ** 10;
echo $st . "\n";



$squareRoot = sqrt(245);
echo $squareRoot . "\n";



$array1 = [4, 2, 5, 19, 13, 0, 10];
$sumOfSquares = 0;
foreach ($array1 as $element) {
    $sumOfSquares += $element ** 2;
}
$answer = sqrt($sumOfSquares);
echo $answer . "\n";



$num1 = sqrt(379);
$sqrt1Precision0 = round($num1);
$sqrt1Precision1 = round($num1, 1);
$sqrt1Precision2 = round($num1, 2);
echo "Square root of 379: $sqrt1Precision0, $sqrt1Precision1, $sqrt1Precision2\n";



$num2 = sqrt(587);
$sqrt2 = ['floor' => floor($num2), 'ceil' => ceil($num2)];
echo "Square root of 587: ", $sqrt2['floor'], ", ", $sqrt2['ceil'], "\n";



$array2 = [4, -2, 5, 19, -130, 0, 10];
$mx = max($array2);
$mn = min($array2);
echo "max = $mx, min = $mn\n";



echo "random = ", rand(1, 100), "\n";



$array3 = [];
for ($i = 0; $i < 10; $i++) {
    $array3[$i] = rand(1, 100);
}
foreach ($array3 as $element) {
    echo $element . " ";
}
echo "\n";



$a = -69;
$b = 34;
echo "|a - b| = ", abs($a - $b), "\n";



$array4 = [1, 2, -1, -2, 3, -3];
$array5 = array_map('abs', $array4);
foreach ($array5 as $element) {
    echo $element . " ";
}
echo "\n";


$num3 = 9841;
$divisors = [];

for ($i = 1; $i <= sqrt($num3); $i++) {
    if ($num3 % $i == 0) {
        if ($i ** 2 != $num3) {
            $divisors[] = $num3 / $i;
        }
        $divisors[] = $i;
    }
}

sort($divisors);

echo "Divisors of $num3: ";
foreach ($divisors as $element) {
    echo $element . " ";
}
echo "\n";



$array6 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
$sum = 0;
$counter = 0;
foreach ($array6 as $element) {
    if ($sum <= 10) {
        $sum += $element;
        $counter++;
    }
}
echo "To make the sum greater than 10, you need to add the first $counter elements of the array";