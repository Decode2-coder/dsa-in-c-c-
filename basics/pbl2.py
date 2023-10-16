import tkinter as tk
def first_fit(memory_blocks, process_list):
    allocation = [-1] * len(process_list)
    for i in range(len(process_list)):
        for j in range(len(memory_blocks)):
            if memory_blocks[j] >= process_list[i]:
                allocation[i] = j
                memory_blocks[j] -= process_list[i]
                break
    return allocation
def best_fit(memory_blocks, process_list):
    memory_copy = memory_blocks.copy()
    allocation = [-1] * len(process_list)
    for i in range(len(process_list)):
        best_index = -1
        for j in range(len(memory_copy)):
            if memory_copy[j] >= process_list[i] and (best_index == -1 or memory_copy[j] < memory_copy[best_index]):
                best_index = j
            if best_index != -1:
                allocation[i] = best_index
                memory_copy[best_index] -= process_list[i]
    return allocation

def worst_fit(memory_blocks, process_list):
    memory_copy = memory_blocks.copy()
    allocation = [-1] * len(process_list)
    for i in range(len(process_list)):
        worst_index = -1
        for j in range(len(memory_copy)):
            if memory_copy[j] >= process_list[i] and (worst_index == -1 or memory_copy[j] > memory_copy[worst_index]):
                worst_index = j
                if worst_index != -1:
                    allocation[i] = worst_index
                    memory_copy[worst_index] -= process_list[i]
    return allocation

def allocate_memory():
        
    memory_blocks = [int(x) for x in mem_blocks_entry.get().split()]
    process_list = [int(x) for x in process_entry.get().split()]
    algorithm = algorithm_var.get()
    if algorithm == 1:
        allocation = first_fit(memory_blocks, process_list)
        algorithm_name = "First Fit"
    elif algorithm == 2:
            allocation = best_fit(memory_blocks, process_list)
            algorithm_name = "Best Fit"
    elif algorithm == 3:
        allocation = worst_fit(memory_blocks, process_list)
        algorithm_name = "Worst Fit"
    else:
        result_text.delete('1.0', tk.END)
        result_text.insert(tk.END, "Invalid algorithm selected.")
        return 
    result_text.delete('1.0', tk.END),result_text.insert(tk.END, f"Memory Allocation using {algorithm_name} Algorithm:\n");
    for i in range(len(process_list)): 
        result_text.insert(tk.END, f"Process {i+1}: Block {allocation[i]+1}\n")
root = tk.Tk()
root.configure(bg='black')
root.title("MEMORY ALLOCATION SIMULATOR")
mem_blocks_label = tk.Label(root, text="Memory Blocks\n(separated by space):",bg='bisque')
mem_blocks_entry = tk.Entry(root)
process_label = tk.Label(root, text="Process Sizes\n(separated by space):",bg='bisque')
process_entry = tk.Entry(root)
algorithm_label = tk.Label(root, text="Algorithm for Memory Allocation",bg='bisque')
algorithm_var = tk.IntVar()
algorithm_var.set(1)
first_fit_rb = tk.Radiobutton(root, text="First Fit",
variable=algorithm_var, value=1,bg='orange')
best_fit_rb = tk.Radiobutton(root, text="Best Fit",
variable=algorithm_var, value=2,bg='light blue')
worst_fit_rb = tk.Radiobutton(root, text="Worst Fit",
variable=algorithm_var, value=3,bg='green')
allocate_button = tk.Button(root, text="Allocate Memory",
command=allocate_memory,bg='pink')
result_label = tk.Label(root, text="Allocation Results:",bg='bisque')
result_text = tk.Text(root, height=10)
mem_blocks_label.grid(row=0, column=0, padx=10, pady=10,
sticky="W")
mem_blocks_entry.grid(row=0, column=1, padx=10, pady=10)
process_label.grid(row=1, column=0, padx=10, pady=10,
sticky="W")
process_entry.grid(row=1, column=1, padx=10, pady=10)
algorithm_label.grid(row=2, column=0, padx=10, pady=10,sticky="W")
first_fit_rb.grid(row=2, column=1, padx=10, pady=5, sticky="W")
best_fit_rb.grid(row=3, column=1, padx=10, pady=5, sticky="W")
worst_fit_rb.grid(row=4, column=1, padx=10, pady=5, sticky="W")
allocate_button.grid(row=5, column=0, columnspan=2, padx=10,
pady=10)
result_label.grid(row=6, column=0, padx=10, pady=10, sticky="W")
result_text.grid(row=7, column=0, columnspan=2, padx=10,
pady=10)
root.mainloop()