<?php
function sumChecker($value1, $value2): bool {
    return $value1 + $value2 > 10;
}



function equalityChecker($value1, $value2): bool {
    return $value1 == $value2;
}



$test = 0;
echo ($test == 0) ? 'верно' : '';
echo "\n";



$age = 20;
if ($age < 10 || $age > 99) {
    echo "age less than 10 or more than 99\n";
}
else {
    $sumOfDigits = 0;
    $tempAge = $age;
    while ($tempAge > 0) {
        $sumOfDigits += $tempAge % 10;
        $tempAge = intdiv($tempAge, 10);
    }

    if ($sumOfDigits <= 9) {
        echo "The sum of the age digits is one-digit\n";
    }
    else {
        echo "The sum of the age digits is two-digit\n";
    }
}



$array = [325, -2356, 234];
if (count($array) == 3) {
    echo "Sum of array: " . array_sum($array) . "\n";
}