#include <vector>
#include <cstring>
#include <optional>

#include "Window.hh"

struct QueueFamily {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

class Application {
public:
    static constexpr int width = 512;
    static constexpr int height = 512;
    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

    Application(std::string name);
    ~Application();

    void run();

private:
    void setupDebugMessenger();
    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions();
    void createSurface();
    void pickPhysicalDevice();
    QueueFamily findQueueFamilies(VkPhysicalDevice device);
    bool isSuitableDevice(VkPhysicalDevice device);
    void createLogicalDevice();

    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData);

    VkResult CreateDebugUtilsMessengerEXT(
        VkInstance instance,
        const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDebugUtilsMessengerEXT* pDebugMessenger);

    void DestroyDebugUtilsMessengerEXT(
        VkInstance instance,
        VkDebugUtilsMessengerEXT debugMessenger, const
        VkAllocationCallbacks* pAllocator);


private:
    Window* m_Window;
    VkInstance m_Instance;
    std::string m_Name;
    VkDebugUtilsMessengerEXT m_DebugMessenger;
    VkPhysicalDevice m_PhysicalDevice;
    VkDevice m_Device;
    VkQueue m_GraphicsQueue;
    VkQueue m_PresentQueue;
    VkSurfaceKHR m_Surface;
};
