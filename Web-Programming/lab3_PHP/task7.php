<?php
function printStringReturnNumber(): int {
    echo "Hello World!";
    return 22;
}

$my_num = printStringReturnNumber();
echo $my_num;