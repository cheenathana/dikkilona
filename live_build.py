#!/usr/bin/env python3

"""
Python script which uses watchdog to monitor file changes. If any detected
then try to compile the code using make.
"""
import time
import os
import subprocess

from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

PROCESS_ID = 0
BANNER_MESSAGE  = (
"""
         LIVE BUILD TOOL (Alpha)
         =======================
Start this script, while writing the code.
It will automatically detect the file changes and compiles the code.
The sceript relies on Makefile. 

Also it will run the executable, if the build was success.
Happy coding!!!
""")


class CompileOnFileModify(FileSystemEventHandler):
    def on_modified(self, event):
        """
        Called when a file or dir is modified 

        1. If any file changes detected run make automatically
        2. If build got failed handle it
        3. If build got success, then run the executable and record its PID
        """

        if not event.is_directory:
            global PROCESS_ID

            # we are compiling the code only if file changes are detected
            try:
                # checking if the make completed successfully
                subprocess.check_call("make")

                # checking if previous process is running
                if PROCESS_ID:
                    os.system("kill {}".format(PROCESS_ID))

                # If build was success, run the executable and get the processID
                process = subprocess.Popen("bin/dikkilona", shell=False)
                PROCESS_ID = process.pid

            except subprocess.CalledProcessError:
                # Killing if process is already running
                if PROCESS_ID:
                    os.system("kill {}".format(PROCESS_ID))

                print("[-] *** BUILD FAILED ***")
                print("===============================")




# Execution begins here
if __name__ == "__main__":
    """
    THINGS TO DO
    ============
    1. Create a observer instance
    2. Override FileSystemEventHandeler based on specific action to take
    3. Schedule the oserver by passing in event_handler, path to monitor
    4. Start the observer
    5. Set a sleep time
    6. While terminating, join the threads
    """
    print(BANNER_MESSAGE)

    watcher = Observer()
    event_handler = CompileOnFileModify()

    paths_to_monitor = ('src', 'libs')

    for path in paths_to_monitor:
        watcher.schedule(event_handler, path, recursive = True)

    print("[+] Starting WatchDog...")
    watcher.start()

    print("[+] Started watching {}".format(paths_to_monitor))

    try:
        while True:
            # specify time frequency to monitor for file changes (every 5 sec)
            time.sleep(5)
    except KeyboardInterrupt:
        watcher.stop()

    watcher.join()
