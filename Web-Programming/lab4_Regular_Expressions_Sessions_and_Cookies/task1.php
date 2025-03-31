<?php
$str = "vaav vaaav vav vbbbv vpppv   v vcccv vpv";
$regexp = "/(?=(v...v))/"; // Вариант 22, 'v' + три любых символа + 'v'
$matches = [];

$count = preg_match_all($regexp, $str, $matches);
$matches = $matches[1];

echo "Найдено строк: $count \n";
var_dump($matches);