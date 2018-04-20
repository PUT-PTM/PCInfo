using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;
using System.Management;
using System.Management.Instrumentation;
using System.Threading;
namespace ConsoleApp1
{
    class Program
    {
        static SerialPort _serialPort;
        static ManagementObjectSearcher searcher;
        static void Main(string[] args)
        {
            _serialPort = new SerialPort();
            _serialPort.PortName = SetPortName();
            _serialPort.BaudRate = 115200;
            _serialPort.Parity = Parity.None;
            _serialPort.DataBits = 8;
            _serialPort.StopBits = StopBits.One;
            _serialPort.Handshake = Handshake.None;
            _serialPort.ReadTimeout = 500;
            _serialPort.WriteTimeout = 500;
            _serialPort.Open();
            string message;
            while (true)
            {
                GetInfo();
                message = _serialPort.ReadLine();
                Console.WriteLine(message);
                System.Threading.Thread.Sleep(500);
            }

        }
        public static string SetPortName()
        {
            string portName;

            Console.WriteLine("Dostepne porty:");
            foreach (string s in SerialPort.GetPortNames())
            {
                Console.WriteLine(" {0}", s);
            }

            Console.Write("Wpisz nazwe portu (np. COM1): ");
            portName = Console.ReadLine();
            return portName;
        }
        public static void GetInfo()
        {
            searcher =  new ManagementObjectSearcher("Select Name from Win32_Processor");
            foreach (ManagementObject cdrom in searcher.Get())
            {
                _serialPort.WriteLine(cdrom.GetPropertyValue("Name").ToString());
            }
            searcher = new ManagementObjectSearcher("Select Name from Win32_SerialPort");
            foreach (ManagementObject cdrom in searcher.Get())
            {
                _serialPort.WriteLine(cdrom.GetPropertyValue("Name").ToString());
            }
            searcher = new ManagementObjectSearcher("Select Name from Win32_VideoController");
            foreach (ManagementObject cdrom in searcher.Get())
            {
                _serialPort.WriteLine(cdrom.GetPropertyValue("Name").ToString());
            }
            searcher = new ManagementObjectSearcher("Select * from Win32_Battery");
            foreach (ManagementObject cdrom in searcher.Get())
            {
                PropertyDataCollection props = cdrom.Properties;
                foreach (PropertyData prop in props)
                {
                    Console.WriteLine("Property name: {0}", prop.Name);
                    Console.WriteLine("Property type: {0}", prop.Type);
                    Console.WriteLine("Property value: {0}", prop.Value);
                }
            }
        }
}
}
