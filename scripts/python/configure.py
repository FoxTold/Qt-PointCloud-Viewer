import subprocess
import platform
import os
## macOS ~/Qt/6.9.1/"
## windows C:\\Qt\\Qt-6.9.1
def configure_project():
    os_name = platform.system()
    qt_path = ""
    generator = ""
    print(os_name.lower())
    match os_name.lower():
        case 'darwin':
            qt_path = os.path.join("~", "Qt", "6.9.1")
            generator = "Xcode"
            print(qt_path)
        case "windows":
            qt_path = os.path.join("C","Qt","Qt-6.9.1")
            generator = "Visual Studio 17 2022"

        case _:
            print("Linux will be added later")
    
    script_dir = os.path.dirname(os.path.abspath(__file__))

    build_dir_path = os.path.abspath(os.path.join(script_dir, "..", "..", "build"))

    os.makedirs(build_dir_path, exist_ok=True)

    try:
        subprocess.run(
            ["cmake", "..", "-G", f"{generator}", f"-DQT_DIR={qt_path}"],
            cwd=build_dir_path,
            check=True
        )
        print("CMake ran successfully.")
    except subprocess.CalledProcessError as e:
        print(f"Error: CMake failed with return code {e.returncode}")
if __name__ == "__main__":
    configure_project()