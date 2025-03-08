class MyClass:
    def __init__(self, array):
        self.array = array

    def __str__(self):
        return f"MyClass with array: {self.array}"

# Example usage
my_instance = MyClass([1, 2, 3, 4, 5])
print(my_instance)
