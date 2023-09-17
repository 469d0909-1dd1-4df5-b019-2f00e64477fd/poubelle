<?php
system("gpio -g read 4");

if($_POST['executer'] == 'ON'){
	system("gpio -g write 4 1");
} else {
	system("gpio -g write 4 0");
}

header('Location: index.php');
?>
