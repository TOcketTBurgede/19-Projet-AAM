#### Lundi 16 mai :
Je commence le code pour le projet, au départ je comptais utiliser la carte UCA mais il manquait
trop de port ducoup j'ai utilisé une de mes propres cartes Arduino pour faire ce projet, j'ai commencé simplement
en programmant la réception de donnée du capteur ultrason sur une distance de 6cm ce qui va actionner un mécanisme, je ne sais pas encore ce que ce sera mais
je commence déjà le travail en amont.

#### Jeudi 19 mai :
J'ai un peu de temps libre, alors je m'avance sur le projet.
Timothé m'a dit qu'il serait plus judicieux de faire tirer un fil avec le servomoteur et abandonner la pompe car ça impliquer trop de soucis.
Je m'exécute donc et programme la rotation du servomoteur lorsqu'on capte quelque chose avec le capteur.

#### Lundi 23 mai : 
Je vais au Fablab avec Timothé et on se répartis les tâches : je continue de m'occuper du code et lui cherche les pièces et supervise.
J'amène le distributeur manuel et utilise du fil d'étain pour servir de fil actionnant le distributeur mais il est trop fragile et casse.
Je me doutais que les résultats ne seraient pas super concluant mais je n'avais que ça chez moi et j'avais pas trouvé au Fablab quelque chose pour le remplacer
J'ai eu l'idée de programmer un écran OLED pour compter le nombre de passages où des gens se sont laver les mains, mais je n'ai pas eu le temps ducoup je finirai demain

#### Mardi 24 mai :
Aujourd'hui je suis allé au Fablab avec Timothé pour avancer sur le projet, j'ai travaillé sur le code pour la serrure connectée ainsi que sur un moyen de projeter le gel un peu plus loin, pour le prototype j'en suis venu à l'utilisation d'un bout de stylo à bille pour allonger la distance où aller atterrir le gel.
J'ai finis la programmation de l'écran et il fonctionne. Seul problème étant qu'a chaque fois qu'on tester la machine on mettait du gel de partout alors il fallait débranché certaines fois le servomoteur
Vu que nous avions finis avec Timothé le plus gros du travail, il fallait s'occuper du boitier et qu'il soit en bois ou bien imprimé, il fallait mettre une sorte de verrou pour que n'importe qui n'est pas accès à l'intérieur, alors je me suis attelé à programmé une sorte de serrure connecté en passant un badge pour dévérouillé la boite avec un module RFID
En rentrant chez moi j'ai pensé à une manière future de remplir le distributeur sans tout arracher/retirer et j'ai alors pensé à percé un trou sur le dessus du distributeur, on y mettra une paille métallique et un entonnoir  pour versé le gel via la fente.

#### Mercredi 25 mai :

Timothé m'a ramené le boitier pour que je puisse mettre la serrure connectée, j'ai utilisé un servomoteur, une carte RFID et un crochet pour la faire : lorsqu'on passe le badge il va afficher sur l'écran "Accès autorisé" ou bien "Accès refusé" si ce n'est pas le bon badge.
J'ai percé des trous dans les planches pour permettre au capteur d'ultrasons de capter l'extérieur, un autre pour permettre de brancher la carte Arduino à mon ordinateur pour alimenter l'AAM et un dernier pour faire travers des câbles vers l'écran OLED se trouvant à l'extérieur du boitier, j'ai commencé à collé certains composants comme la carte Arduino, le morceau de breadboard et le servomoteur qui sert de verrou. J'ai assemblé les morceaux avec de la colle mais au fur et a mesure j'ai eu de nombreuses difficultés car les câbles se débranchés, certains composants ne tenez pas j'en ai eu pour toute la journée mais j'ai finalement pu assembler tout le dispositif et le tester.
