SELECT COUNT(id_film) AS 'films'
FROM historique_membre
WHERE (DATE(date) BETWEEN '2006-10-30' AND '2007-27-07') OR DATE(date) LIKE '%-12-24';
