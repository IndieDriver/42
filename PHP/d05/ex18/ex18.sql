SELECT nom FROM distrib
WHERE id_distrib=42 OR (id_distrib BETWEEN 62 AND 69) OR id_distrib=71 OR (id_distrib BETWEEN 88 AND 90)
OR CHAR_LENGTH(nom)=(CHAR_LENGTH(REPLACE(LOWER(nom), 'y', '')) + 2)
LIMIT 2, 5;
