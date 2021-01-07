#import <Foundation/NSObject.h>
#import <dispatch/dispatch.h>

@class NSArray, NSData, NSDictionary, NSMutableDictionary, NSString, NSURL;

FOUNDATION_EXPORT NSString * const NSGlobalDomain;
FOUNDATION_EXPORT NSString * const NSArgumentDomain;
FOUNDATION_EXPORT NSString * const NSRegistrationDomain;
FOUNDATION_EXPORT NSString * const NSUserDefaultsDidChangeNotification;

// The type resides in CF

@interface NSUserDefaults : NSObject
{
    NSString *_suiteName;
    NSMutableDictionary *_volatileDomains;

    dispatch_queue_t _synchronizeQueue;
    dispatch_queue_t _notificationQueue;
    dispatch_source_t _synchronizeTimer;

    NSUserDefaults * __strong *_weakSelfPointer;
}

#undef PREFS_TYPE

@end

// The actual methods are defined in a category and
// implemented inside Foundation

@interface NSUserDefaults (NSUserDefaults)

+ (NSUserDefaults *)standardUserDefaults;
+ (void)resetStandardUserDefaults;

- (id)init;
- (id)initWithSuiteName:(NSString *)suiteName;
- (id)initWithUser:(NSString *)username;

- (id)objectForKey:(NSString *)key;
- (void)setObject:(id)value forKey:(NSString *)key;
- (void)removeObjectForKey:(NSString *)key;
- (NSString *)stringForKey:(NSString *)key;
- (NSArray *)arrayForKey:(NSString *)key;
- (NSDictionary *)dictionaryForKey:(NSString *)key;
- (NSData *)dataForKey:(NSString *)key;
- (NSArray *)stringArrayForKey:(NSString *)key;
- (NSInteger)integerForKey:(NSString *)key;
- (float)floatForKey:(NSString *)key;
- (double)doubleForKey:(NSString *)key;
- (BOOL)boolForKey:(NSString *)key;
- (NSURL *)URLForKey:(NSString *)key;
- (void)setInteger:(NSInteger)value forKey:(NSString *)key;
- (void)setFloat:(float)value forKey:(NSString *)key;
- (void)setDouble:(double)value forKey:(NSString *)key;
- (void)setBool:(BOOL)value forKey:(NSString *)key;
- (void)setURL:(NSURL *)URL forKey:(NSString *)key;
- (void)registerDefaults:(NSDictionary *)registrationDictionary;
- (void)addSuiteNamed:(NSString *)suiteName;
- (void)removeSuiteNamed:(NSString *)suiteName;
- (NSDictionary *)dictionaryRepresentation;
- (NSArray *)volatileDomainNames;
- (NSDictionary *)volatileDomainForName:(NSString *)domainName;
- (void)setVolatileDomain:(NSDictionary *)domain forName:(NSString *)domainName;
- (void)removeVolatileDomainForName:(NSString *)domainName;
- (NSArray *)persistentDomainNames;
- (NSDictionary *)persistentDomainForName:(NSString *)domainName;
- (void)setPersistentDomain:(NSDictionary *)domain forName:(NSString *)domainName;
- (void)removePersistentDomainForName:(NSString *)domainName;
- (BOOL)synchronize;
- (BOOL)objectIsForcedForKey:(NSString *)key;
- (BOOL)objectIsForcedForKey:(NSString *)key inDomain:(NSString *)domain;

@end
