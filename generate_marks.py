# -*- coding: utf-8 -*-
"""
Created on Thu Apr 21 17:12:49 2016

@author: Yan
"""

import numpy as np
N = 5000 #количество людей

films = open('films.txt', 'r')
rating = open('rating.txt', 'w')

films_list = [line.strip() for line in films]
films.close()

N_films = len(films_list)
for i in range(0, N):
    mark1 = mark2 = mark3 = 0
    while(mark1 == mark2 == mark3):    
        mark1 = np.random.choice(range(0, N_films))
        mark2 = np.random.choice(range(0, N_films))
        mark3 = np.random.choice(range(0, N_films))
    rating.write(str(mark1) + ' ' + str(mark2) + ' ' + str(mark3) + '\n')
rating.close()
        
