<?php
$text = $_POST["textarea"];
$regexp = "/([a-zA-Z0-9_+.-]+)@([a-z-]+)\.([a-z]+)/";
$matches = [];

$count = preg_match_all($regexp, $text, $matches);
echo "There are <b>$count e-mail addresses</b> in the text!";
?>
