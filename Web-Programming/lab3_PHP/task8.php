<?php

function increaseEnthusiasm($string): string {
    return $string . "!";
}

echo increaseEnthusiasm("Hello World") . "\n";



function repeatThreeTimes($string): string {
    return $string . $string . $string;
}

echo repeatThreeTimes("Porosyonka") . "\n";



echo increaseEnthusiasm(repeatThreeTimes("Piglet")) . "\n";



function cut($string, $numOfChars = 10): string {
    return substr($string, 0, $numOfChars);
}

echo cut("Calling a function without a second argument") . "\n";
echo cut("Calling a function with a second argument", 5) . "\n";



$array = [0, 1, 1, 2, 3, 5, 8, 13];

function printRecursively($array, $index = 0): void {
    echo $array[$index] . " ";
    if($index + 1 < count($array)){
        printRecursively($array, $index + 1); 
    }
}

printRecursively($array);



function recursiveSumOfDigits($number): int {
    $sumOfDigits = 0;

    while ($number > 0) {
        $sumOfDigits += $number % 10;
        $number = intdiv($number, 10);
    }

    if ($sumOfDigits <= 9) {
        return $sumOfDigits;
    }
    return recursiveSumOfDigits($sumOfDigits);
}

echo "\n" . recursiveSumOfDigits(5555) . "\n";