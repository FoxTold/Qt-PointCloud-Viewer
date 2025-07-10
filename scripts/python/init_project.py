import subprocess
import os

def init_repo():
    try:
        print("Running git submodule init...")
        subprocess.run(["git", "submodule", "init"], check=True)
    except subprocess.CalledProcessError as e:
        print(f"An error occurred while initializing the repository: {e}")
        return False

if __name__ == "__main__":
    if init_repo():
        print("Repository initialized successfully.")
    else:
        print("Failed to initialize the repository.")