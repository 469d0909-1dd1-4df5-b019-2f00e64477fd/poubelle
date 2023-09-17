<!doctype html>
<html lang="fr">
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<title>Controle GPIO</title>
	</head>
	<body>
		<div>
			<h1>État</h1>
			<?php
				$statut = system("gpio -g read 4");
				if($statut == "0"){
					echo "Éteinte";
				} else {
					echo "Allumée";
				}
			?>
		</div>
		<!-- script.php correspond à rpi_gpio_script1.php dans le dossier GitHub -->
		<form id="buttons" action="script.php" method="post">
			<input type="submit" name="executer" value="ON" class="button" id="ON">
			<br>
			<input type="submit" name="executer" value="OFF" class="button" id="OFF">
		</form>
	</body>
</html>

