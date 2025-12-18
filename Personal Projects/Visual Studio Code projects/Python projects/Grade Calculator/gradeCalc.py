# Name: Alexander Bordenet
# Date: 11/29/25
# Purpose: A program to calculate and display a student's grade based on input scores.


def calculateAvgGrade(scores, totalPoints):
    total = sum(scores)
    count = len(scores)
    maxPoints = sum(totalPoints)
    if count == 0 or totalPoints == 0:
        return 0.0
    average = (total / (maxPoints)) * 100
    return [average, total, maxPoints]

def main():
    totalWeights = []

    while True:
        scores = []
        totalScores = []  
        print("Enter student scores one by one. Type 'done' when finished:")
        while True:
            entry = input("Enter score (or 'done'): ")
            if entry.lower() == 'done':
                break
            try:
                score = float(entry)
                scores.append(score)
                entry = input("Enter max points for assignment: ")
                totalScore = float(entry)
                totalScores.append(totalScore)

            except ValueError:
                print("Invalid input. Please enter a numeric score or 'done'.")

        items = calculateAvgGrade(scores, totalScores)
        print(f"The average grade is: {items[0]:.2f}")
        print(f"Total points earned: {items[1]:.2f} out of {items[2]:.2f}")

        print("\nWhat percentage of your overall grade is this category?")
        weight = float(input("Enter the weight (0.XX): "))
        weightedGrade = (items[0] * (weight / 100))
        totalWeights.append(weightedGrade)
        print(f"The weighted grade for this category is: {weightedGrade:.2f}")

        another = input("\nDo you want to enter another category? (yes/no): ")
        if another.lower() != 'yes':
            break
    
    overallWeightedGrade = sum(w for w in totalWeights)
    print(f"\nThe overall weighted grade is: {overallWeightedGrade:.2f}")

main()