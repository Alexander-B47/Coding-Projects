# Name: Alexander Bordenet
# Date: 11/22/2025
# Purpose: A simple RPG-type program that is to help me work on my Python skills.
# This will be displayed to the console because I am not familiar with GUIs yet.
# This will be the file for calculating the level based on experience points.

# Important: This class is using snake case to get used to using it more often.
# I am still not convinced that it is better than camel case, I'll probably stick to camel case, even though it isn't convention.

import math
import random

class LevelCalc:

    LEVEL_BASE_XP = 100  # Base XP required for level 1
    GROWTH_RATIO = 1.2   # Growth ratio for XP requirement
    LEVEL_CAP = 100     # Maximum level
    LIMIT_BREAK_LEVEL = 30 # Level at which limit break occurs (higher growth ratio)
    LIMIT_BREAK_GROWTH_RATIO = 1.5 # Growth ratio after limit break

    @staticmethod
    def xp_for_level(L, A=100, r=1.2):
        """XP required to go from level L to L+1 (L is integer >= 0)."""
        return int(round(A * (r ** L)))
    @staticmethod
    def cumulative_xp_to_level(L, A=100, r=1.2):
        """Total XP required to reach level L from level 0 (sum of XP(0) .. XP(L-1))."""
        if r == 1:
            return A * L
        return int(round(A * (r**L - 1) / (r - 1)))

    @staticmethod
    def level_up(current_xp, current_level):
        """Determine new level based on current XP and level."""
        level = current_level
        xp = current_xp

        while level < LevelCalc.LEVEL_CAP:
            xp_needed = LevelCalc.xp_for_level(level, LevelCalc.LEVEL_BASE_XP, 
                                              LevelCalc.LIMIT_BREAK_GROWTH_RATIO if level >= LevelCalc.LIMIT_BREAK_LEVEL else LevelCalc.GROWTH_RATIO)
            if xp >= xp_needed:
                xp -= xp_needed
                level += 1
            else:
                break
        return level

    # Example usage
    def main():
        A = 100          # XP needed for level 0 -> 1
        r = 1.2     # growth ratio; try 1.2, 1.3, or 2.0
        for lvl in range(1, 100):
            if lvl % 10 == 0:
                r = round(r + (0.0005 * random.randint(1,10)), 4) # increase the growth ratio slightly every 10 levels
                print(f"\nNew growth ratio r={r}\n")
            print(f"Level {lvl} -> {lvl+1}: {LevelCalc.xp_for_level(lvl, A, r):,} XP")
        print("Total to reach level 100:", LevelCalc.cumulative_xp_to_level(100, A, r))