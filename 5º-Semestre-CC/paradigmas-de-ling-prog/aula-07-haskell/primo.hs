-- solucao usando if.. then .. else
primo n = primo_aux n (n-1)
  where primo_aux n d = if d == 1 then True else if mod n d ==  0 then False else primo_aux n (d - 1)

-- solucao usando guarda 
primo n = primo_aux n (n-1)
  where primo_aux n d
          | d == 1 = True 
          | mod n d ==  0 = False
          | otherwise = primo_aux n (d - 1)