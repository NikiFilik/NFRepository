<?php
$array = [12, 325, 237, 1];
$arithmeticAverage = array_sum($array) / count($array);
echo $arithmeticAverage . "\n";



$sum1to100 = (1 + 100) * 100 / 2; // По формуле суммы арифметической прогресии S = (a(1) + a(n)) * n / 2
echo $sum1to100 . "\n";



$squareRoots = array_map('sqrt', $array);
foreach ($squareRoots as $element) {
    echo $element . " ";
}
echo "\n";



$letters = range('a', 'z');
$numbers = range(1, 26);
$alphabet = array_combine($letters, $numbers);
foreach ($alphabet as $element) {
    echo $element . " ";
}
echo "\n";



$numbers = '1234567890';
$pairs = str_split($numbers, 2);
$sumOfPairs = array_sum($pairs);
echo $sumOfPairs . "\n";