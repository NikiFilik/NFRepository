<?php
$str = "2x7x23x9827";
$regexp = "/[0-9]+/"; // Вариант 22, Заменить числа на произведение их цифр

$result = preg_replace_callback(
    $regexp,
    function ($matches) {
        return array_product(str_split($matches[0]));
    },
    $str
);

echo $result;